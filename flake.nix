{
  description = "Trying to build openmw";

  inputs.nixpkgs.url = "nixpkgs/nixos-unstable";
  inputs.devshell.url = "github:numtide/devshell";
  inputs.flake-utils.url = "github:numtide/flake-utils";

  outputs = { self, flake-utils, nixpkgs, devshell, fenix }: 
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs {
        inherit system;

        overlays = [ 
          devshell.overlays.default 
        ];
      };

      GL = "GLVND"; # or "LEGACY";

      osg' = (pkgs.openscenegraph.override { colladaSupport = true; }).overrideDerivation (old: {
        cmakeFlags = (old.cmakeFlags or [ ]) ++ [
          "-Wno-dev"
          "-DOpenGL_GL_PREFERENCE=${GL}"
          "-DBUILD_OSG_PLUGINS_BY_DEFAULT=0"
          "-DBUILD_OSG_DEPRECATED_SERIALIZERS=0"
        ] ++ (map (e: "-DBUILD_OSG_PLUGIN_${e}=1") [ "BMP" "DAE" "DDS" "FREETYPE" "JPEG" "OSG" "PNG" "TGA" ]);
      });

      bullet' = pkgs.bullet.overrideDerivation (old: {
        cmakeFlags = (old.cmakeFlags or [ ]) ++ [
          "-Wno-dev"
          "-DOpenGL_GL_PREFERENCE=${GL}"
          "-DUSE_DOUBLE_PRECISION=ON"
          "-DBULLET2_MULTITHREADING=ON"
        ];
      });

    in {
      devShell.${system} = with pkgs; pkgs.mkShell {
        buildInputs = [
          SDL2
          boost
          bullet'
          ffmpeg
          xorg.libXt
          luajit
          lz4
          mygui
          openal
          osg'
          recastnavigation
          unshield
          yaml-cpp
          glfw
          glm
          lua
          libGL
          libGL.dev
          mesa
        ];

        shellHook = with pkgs; 
        ''export INCLUDES_PATH="${pkgs.lib.makeLibraryPath [ libGL libGL.dev lz4]}"
          export OPENGL_INCLUDE_DIR="${libGL.dev}/include"
          export OPENGL_opengl_LIBRARY=${libGL}/lib"
        '';
      };
    };
}

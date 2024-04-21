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
        overlays = [ devshell.overlays.default ];
      };

      raknet = pkgs.stdenv.mkDerivation {
        pname = "raknet";
        version = "unstable-2020-01-19";

        src = pkgs.fetchFromGitHub {
          owner = "TES3MP";
          repo = "CrabNet";
          # usually fixed:
          # https://github.com/GrimKriegor/TES3MP-deploy/blob/d2a4a5d3acb64b16d9b8ca85906780aeea8d311b/tes3mp-deploy.sh#L589
          rev = "19e66190e83f53bcdcbcd6513238ed2e54878a21";
          sha256 = "WIaJkSQnoOm9T7GoAwmWl7fNg79coIo/ILUsWcbH+lA=";
        };

        patches = [
          # gcc-13 build fix:
          #   https://github.com/TES3MP/CrabNet/pull/18
          (pkgs.fetchpatch {
            name = "gcc-13.patch";
            url =
              "https://github.com/TES3MP/CrabNet/commit/3ec9a338a7cefd5cc751c9d29095cafa4c73be20.patch";
            hash = "sha256-zE87icjX9GSnApgKQXj0K4IjlrReV/upFLjVgNYkNfM=";
          })
        ];

        cmakeFlags = [ "-DCRABNET_ENABLE_DLL=OFF" ];

        nativeBuildInputs = [ pkgs.cmake ];
      };

      GL = "GLVND"; # or "LEGACY";

      osg' = (pkgs.openscenegraph.override {
        colladaSupport = true;
      }).overrideDerivation (old: {
        cmakeFlags = (old.cmakeFlags or [ ]) ++ [
          "-Wno-dev"
          "-DOpenGL_GL_PREFERENCE=${GL}"
          "-DBUILD_OSG_PLUGINS_BY_DEFAULT=0"
          "-DBUILD_OSG_DEPRECATED_SERIALIZERS=0"
        ] ++ (map (e: "-DBUILD_OSG_PLUGIN_${e}=1") [
          "BMP"
          "DAE"
          "DDS"
          "FREETYPE"
          "JPEG"
          "OSG"
          "PNG"
          "TGA"
        ]);
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
      devShell.${system} = pkgs.mkShell {
        buildInputs = with pkgs; [
          cmake
          pkg-config

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

          raknet

          glfw
          glm
          lua
          libGL
          libGL.dev
          mesa
          qt5Full
        ];

        shellHook =
          let cpath = pkgs.lib.makeIncludePath [ pkgs.libGL.dev raknet ];
          in ''
            export CPATH="${cpath}";
          '';
      };
    };
}

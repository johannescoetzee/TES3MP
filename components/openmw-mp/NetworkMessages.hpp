#ifndef OPENMW_NETWORKMESSAGES_HPP
#define OPENMW_NETWORKMESSAGES_HPP

#include <MessageIdentifiers.h>

enum GameMessages
{
    _ID_UNUSED = ID_USER_PACKET_ENUM+1,
    ID_USER_MYID,
    ID_USER_DISCONNECTED,
    ID_CHAT_MESSAGE,

    ID_SYSTEM_HANDSHAKE,
    ID_LOADED,
    ID_GUI_MESSAGEBOX,
    
    ID_PLAYER_BASEINFO,
    ID_PLAYER_BEHAVIOR,
    ID_PLAYER_CHARGEN,
    ID_PLAYER_SPELLS_ACTIVE,
    ID_PLAYER_ANIM_FLAGS,
    ID_PLAYER_ANIM_PLAY,
    ID_PLAYER_ATTACK,
    ID_PLAYER_ATTRIBUTE,
    ID_PLAYER_BOOK,
    ID_PLAYER_BOUNTY,
    ID_PLAYER_CELL_CHANGE,
    ID_PLAYER_CELL_STATE,
    ID_PLAYER_CHARCLASS,
    ID_PLAYER_DEATH,
    ID_PLAYER_DISPOSITION,
    ID_PLAYER_EQUIPMENT,
    ID_PLAYER_FACTION,
    ID_PLAYER_INPUT,
    ID_PLAYER_INVENTORY,
    ID_PLAYER_JAIL,
    ID_PLAYER_JOURNAL,
    ID_WORLD_KILL_COUNT,
    ID_PLAYER_LEVEL,
    ID_PLAYER_MISCELLANEOUS,
    ID_PLAYER_MOMENTUM,
    ID_PLAYER_POSITION,
    ID_PLAYER_QUICKKEYS,
    ID_WORLD_REGION_AUTHORITY,
    ID_PLAYER_REPUTATION,
    ID_PLAYER_RESURRECT,
    ID_PLAYER_REST,
    ID_PLAYER_SHAPESHIFT,
    ID_PLAYER_SKILL,
    ID_PLAYER_SPEECH,
    ID_PLAYER_SPELLBOOK,
    ID_PLAYER_STATS_DYNAMIC,
    ID_PLAYER_TOPIC,
    ID_PLAYER_TOPIC_INFO,

    ID_ACTOR_LIST,
    ID_ACTOR_AUTHORITY,
    ID_ACTOR_TEST,
    ID_ACTOR_AI,
    ID_ACTOR_ANIM_FLAGS,
    ID_ACTOR_ANIM_PLAY,
    ID_ACTOR_ATTACK,
    ID_ACTOR_CELL_CHANGE,
    ID_ACTOR_DEATH,
    ID_ACTOR_EQUIPMENT,
    ID_ACTOR_CAST,
    ID_ACTOR_POSITION,
    ID_ACTOR_SPEECH,
    ID_ACTOR_STATS_DYNAMIC,

    ID_OBJECT_ACTIVATE,
    ID_OBJECT_ANIM_PLAY,
    ID_OBJECT_ATTACH,
    ID_OBJECT_SOUND,
    ID_OBJECT_DELETE,
    ID_OBJECT_LOCK,
    ID_OBJECT_MOVE,
    ID_OBJECT_PLACE,
    ID_OBJECT_HIT,
    ID_OBJECT_ROTATE,
    ID_OBJECT_SCALE,
    ID_OBJECT_SPAWN,
    ID_OBJECT_STATE,
    ID_OBJECT_TRAP,
    
    ID_CONSOLE_COMMAND,
    ID_CONTAINER,
    ID_DOOR_DESTINATION,
    ID_DOOR_STATE,
    ID_MUSIC_PLAY,
    ID_VIDEO_PLAY,

    ID_CLIENT_SCRIPT_LOCAL,
    ID_OBJECT_DIALOGUE_CHOICE,
    ID_SCRIPT_MEMBER_SHORT,
    ID_OBJECT_MISCELLANEOUS,
    ID_CLIENT_SCRIPT_GLOBAL,
    ID_OBJECT_RESTOCK,

    ID_GAME_SETTINGS,
    ID_GAME_PREINIT,

    ID_CLIENT_SCRIPT_SETTINGS,
    ID_CELL_RESET,
    ID_RECORD_DYNAMIC,
    ID_WORLD_COLLISION_OVERRIDE,
    ID_WORLD_MAP,
    ID_WORLD_TIME,
    ID_WORLD_WEATHER,

    ID_PLAYER_ITEM_USE,
    ID_PLAYER_CAST,
    ID_PLAYER_ALLY,
    ID_WORLD_DESTINATION_OVERRIDE,
    ID_ACTOR_SPELLS_ACTIVE,
    ID_PLAYER_COOLDOWNS,
    ID_PLACEHOLDER
};

enum OrderingChannel
{
    CHANNEL_SYSTEM = 0,
    CHANNEL_ACTOR,
    CHANNEL_PLAYER,
    CHANNEL_OBJECT,
    CHANNEL_MASTER,
    CHANNEL_WORLDSTATE
};


#endif //OPENMW_NETWORKMESSAGES_HPP

#include "Dialogue.hpp"

#include <components/openmw-mp/NetworkMessages.hpp>

#include <apps/openmw-mp/Script/ScriptFunctions.hpp>
#include <apps/openmw-mp/Networking.hpp>

using namespace mwmp;

void DialogueFunctions::ClearTopicChanges(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->topicChanges.clear();
}

unsigned int DialogueFunctions::GetTopicChangesSize(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->topicChanges.size();
}

void DialogueFunctions::AddTopic(unsigned short pid, const char* topicId) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::Topic topic;
    topic.topicId = topicId;

    player->topicChanges.push_back(topic);
}

void DialogueFunctions::AddTopicInfo(unsigned short pid, const char* topicId, const char* infoId, const char* actorName) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::TopicInfo topicInfo;
    topicInfo.topicId = topicId;
    topicInfo.infoId = infoId;
    topicInfo.actorName = actorName;

    player->topicInfoChanges.push_back(topicInfo);
}

const char *DialogueFunctions::GetTopicId(unsigned short pid, unsigned int index) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, "");

    if (index >= player->topicChanges.size())
        return "invalid";

    return player->topicChanges.at(index).topicId.c_str();
}

void DialogueFunctions::SendTopicChanges(unsigned short pid, bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_TOPIC);
    packet->setPlayer(player);

    if (!skipAttachedPlayer)
        packet->Send(false);
    if (sendToOtherPlayers)
        packet->Send(true);
}

void DialogueFunctions::SendTopicInfoChanges(unsigned short pid, bool sendToOtherPlayers, bool skipAttachedPlayer) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_TOPIC_INFO);
    packet->setPlayer(player);

    if (!skipAttachedPlayer)
        packet->Send(false);
    if (sendToOtherPlayers)
        packet->Send(true);
}

unsigned int DialogueFunctions::GetTopicInfoChangesSize(unsigned short pid) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, 0);

    return player->topicInfoChanges.size();
}

const char *DialogueFunctions::GetTopicInfoTopicId(unsigned short pid, unsigned int index) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, "");

    if (index >= player->topicInfoChanges.size())
        return "invalid";

    return player->topicInfoChanges.at(index).topicId.c_str();
}

const char *DialogueFunctions::GetTopicInfoInfoId(unsigned short pid, unsigned int index) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, "");

    if (index >= player->topicInfoChanges.size())
        return "invalid";

    return player->topicInfoChanges.at(index).infoId.c_str();
}

const char *DialogueFunctions::GetTopicInfoActorName(unsigned short pid, unsigned int index) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, "");

    if (index >= player->topicInfoChanges.size())
        return "invalid";

    return player->topicInfoChanges.at(index).actorName.c_str();
}

void DialogueFunctions::PlayAnimation(unsigned short pid, const char* groupname, int mode, int count, bool persist) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->animation.groupname = groupname;
    player->animation.mode = mode;
    player->animation.count = count;
    player->animation.persist = persist;

    mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_ANIM_PLAY);
    packet->setPlayer(player);

    packet->Send(false);
    player->sendToLoaded(packet);
}

void DialogueFunctions::PlaySpeech(unsigned short pid, const char* sound) noexcept
{
    Player *player;
    GET_PLAYER(pid, player, );

    player->sound = sound;

    mwmp::PlayerPacket *packet = mwmp::Networking::get().getPlayerPacketController()->GetPacket(ID_PLAYER_SPEECH);
    packet->setPlayer(player);

    packet->Send(false);
    player->sendToLoaded(packet);
}

// All methods below are deprecated versions of methods from above

void DialogueFunctions::InitializeTopicChanges(unsigned short pid) noexcept
{
    ClearTopicChanges(pid);
}

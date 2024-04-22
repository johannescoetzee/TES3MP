#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketPlayerTopicInfo.hpp"
#include <components/debug/debuglog.hpp>

using namespace mwmp;

PacketPlayerTopicInfo::PacketPlayerTopicInfo(RakNet::RakPeerInterface *peer) : PlayerPacket(peer)
{
    packetID = ID_PLAYER_TOPIC_INFO;
}

void PacketPlayerTopicInfo::Packet(RakNet::BitStream *newBitstream, bool send)
{
    PlayerPacket::Packet(newBitstream, send);

    uint32_t count;

    if (send)
    {
        count = static_cast<uint32_t>(player->topicInfoChanges.size());
        Log(Debug::Error) << "Sending count " << count;
    }

    RW(count, send);

    if (!send)
    {
        Log(Debug::Error) << "Received count " << count;
        player->topicInfoChanges.clear();
        player->topicInfoChanges.resize(count);
    }

    for (auto &&topicInfo : player->topicInfoChanges)
    {
        RW(topicInfo.topicId, send, true);
        RW(topicInfo.infoId, send, true);
        RW(topicInfo.actorName, send, true);
    }
}

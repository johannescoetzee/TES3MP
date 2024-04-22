#ifndef OPENMW_PACKETPLAYERTOPIC_INFO_HPP
#define OPENMW_PACKETPLAYERTOPIC_INFO_HPP

#include <components/openmw-mp/Packets/Player/PlayerPacket.hpp>

namespace mwmp
{
    class PacketPlayerTopicInfo : public PlayerPacket
    {
    public:
        PacketPlayerTopicInfo(RakNet::RakPeerInterface *peer);

        virtual void Packet(RakNet::BitStream *newBitstream, bool send);
    };
}

#endif //OPENMW_PACKETPLAYERTOPIC_INFO_HPP

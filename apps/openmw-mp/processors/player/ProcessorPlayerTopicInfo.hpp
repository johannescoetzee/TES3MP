#ifndef OPENMW_PROCESSORPLAYERTOPICINFO_HPP
#define OPENMW_PROCESSORPLAYERTOPICINFO_HPP

#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorPlayerTopicInfo : public PlayerProcessor
    {
    public:
        ProcessorPlayerTopicInfo()
        {
            BPP_INIT(ID_PLAYER_TOPIC_INFO)
        }

        void Do(PlayerPacket &packet, Player &player) override
        {
            DEBUG_PRINTF(strPacketID.c_str());

            Script::Call<Script::CallbackIdentity("OnPlayerTopicInfo")>(player.getId());
        }
    };
}

#endif //OPENMW_PROCESSORPLAYERTOPICINFO_HPP

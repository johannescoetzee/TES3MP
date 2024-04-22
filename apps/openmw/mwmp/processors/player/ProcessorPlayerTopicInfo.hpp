#ifndef OPENMW_PROCESSORPLAYERTOPICINFO_HPP
#define OPENMW_PROCESSORPLAYERTOPICINFO_HPP

#include "../PlayerProcessor.hpp"

namespace mwmp
{
    class ProcessorPlayerTopicInfo final: public PlayerProcessor
    {
    public:
        ProcessorPlayerTopicInfo()
        {
            BPP_INIT(ID_PLAYER_TOPIC_INFO)
        }

        virtual void Do(PlayerPacket &packet, BasePlayer *player)
        {
            LOG_MESSAGE_SIMPLE(TimedLog::LOG_INFO, "Received ID_PLAYER_TOPIC_INFO from server");

            if (isRequest())
            {
                // Entire list of topics cannot currently be requested from players
            }
            else if (player != 0)
            {
                static_cast<LocalPlayer*>(player)->addTopicInfo();
            }
        }
    };
}

#endif //OPENMW_PROCESSORPLAYERTOPICINFO_HPP

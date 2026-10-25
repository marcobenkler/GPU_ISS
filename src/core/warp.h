#pragma once

#include <cstdint>
#include <bitset>
#include "helper.h"

struct Warp {
        //Using uintNN_t for platform independant length
        uint32_t        pc    = 0x0001'0000;           //current pc
        std::bitset<4>  amask = 0b0000;                //which threads are active
        WarpState       state = WarpState::WARP_IDLE;  //If warp is still stuck in pipe etc
        unsigned        warp_id;
        // no cycle accur. uint8_t    age_rank;        //WTO needs to know which warp is oldest to priozitize the same
        // no cycle accur. uint32_t   scoreboard;      //marks pending reg's due to rd will write in that one
        /*
        bool canIssue(unsigned rs1, unsigned rs2, unsigned rd) {
            uint32_t used = ( 1u << rs1) | ( 1u << rs2) | ( 1u << rd);
            return (scoreboard & used) == 0;
            }

        //1u for 1 unsigned 00...001
        //unsigned is natural type for shifting and indexing
        void markPending(unsigned rd) { scoreboard |= (1u << rd); }
        void clearPending(unsigned rd) { scoreboard &= ~(1u << rd); }
        */
};
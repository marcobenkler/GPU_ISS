#pragma once

#include <cstdint>
#include <bitset>
#include "helper.h"

using namespace std;

struct Warp {
        //Using uintNN_t for platform independant length
        uint32_t   pc;         //current pc
        bitset<4>  amask;      //which threads are active
        WarpState  state;      //If warp is still stuck in pipe etc
        uint8_t    age_rank;   //WTO needs to know which warp is oldest to priozitize the same
        uint32_t   scoreboard; //marks pending reg's due to rd will write in that one

        bool canIssue(unsigned rs1, unsigned rs2, unsigned rd) {
            uint32_t used = ( 1u << rs1) | ( 1u << rs2) | ( 1u << rd);
            return (scoreboard & used) == 0;
        }

        //1u for 1 unsigned 00...001
        //unsigned is natural type for shifting and indexing
        void markPending(unsigned rd) { scoreboard |= (1u << rd); }
        void clearPending(unsigned rd) { scoreboard &= ~(1u << rd); }
};
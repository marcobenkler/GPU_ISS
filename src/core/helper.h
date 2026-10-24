#pragma once

#include <cstdint>

enum class MemFault : std::uint8_t {
    // Misaligned:   Address has wrong alignment like 2 on 4-byte access
    // Access Fault: Address is out of range
    InstrAddrMisaligned  = 0, // vals represent mcause
    InstrAccessFault     = 1,
    LoadAddrMisaligned   = 4,
    LoadAccessFault      = 5,
    StoreAddrMisaligned  = 6,
    StoreAccessFault     = 7,
    OK                   = 10 // 10 is custom assigned
};

enum class WarpState : std::uint8_t {
    WARP_IDLE,    //No data attached yet
    WARP_READY,   //Can be put in pipe
    WARP_FETCHING,//1 cycle latency hiding from pipeline
    //WARP_STL_MEM, //If Store buffer get's filled // BUFFER JUST RAISES FLAG, so check is canIssue and READY and if is_store !BUFF_FULL
    // if buffer is ful is global, not just one warp
    WARP_BAR,     //Software forces all warps to finish specific pc // also needs check, if bug val is written to mem before bar is removed
    WARP_FINISHED //Warp finished executing
};
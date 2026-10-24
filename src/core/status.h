#pragma once

#include <cstdint>

enum class MemFault : std::uint8_t {
    // Misaligned:   Address has wrong alignment like 2 on 4-byte access
    // Access Fault: Address is out of range
    InstrAddrMisaligned  = 0,
    InstrAccessFault     = 1,
    LoadAddrMisaligned   = 4,
    LoadAccessFault      = 5,
    StoreAddrMisaligned  = 6,
    StoreAccessFault     = 7,
    OK                   = 10
};
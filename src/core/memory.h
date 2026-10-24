#pragma once

#include <cstdint>
#include <vector>
#include <expected>
#include "status.h"

class Memory {
    public:
        Memory();
        std::expected<uint32_t, MemFault> ifetch(uint32_t addr);

        std::expected<uint8_t,  MemFault> load8(uint32_t addr);
        std::expected<uint16_t, MemFault> load16(uint32_t addr);
        std::expected<uint32_t, MemFault> load32(uint32_t addr);

        std::expected<uint8_t,  MemFault> store8(uint32_t addr, uint8_t data);
        std::expected<uint16_t, MemFault> store16(uint32_t addr, uint16_t data);
        std::expected<uint32_t, MemFault> store32(uint32_t addr, uint32_t data);

    private:
        std::vector<uint8_t> imem;
        std::vector<uint8_t> dmem;
};
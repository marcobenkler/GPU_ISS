#pragma once

#include <vector>
#include "memory.h"
#include "warp.h"
#include "helper.h"

class Core {

    public:
        Cpu();
        void load_elf();
        void step();
        DecInstr decode_instr(uint32_t pc);
        bool done();

    private:
        Memory                     mem_;
        std::vector<Warp>          warps_;
        //std::unique_ptr<Scheduler> scheduler_; removed due to switching to functional ISS
        Executor                   executor_;
        Tracer                     tracer_;
};

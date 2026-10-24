#pragma once

#include <vector>
#include "memory.h"
#include "warp.h"

class Gpu {

    public:
        Gpu();
        void load_elf();
        void step();
        bool done();

    private:
        Memory                     mem_;
        std::vector<Warp>          warps_;
        std::unique_ptr<Scheduler> scheduler_;
        Decoder                    decoder_;
        Executor                   executor_;
        Tracer                     tracer_;
};

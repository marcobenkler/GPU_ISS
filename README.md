# Architecture

## GPU
Wrap all components and only implement the method step() to continue 1 instruction and load to load the memory

### Memory
Attributes: several memory regions, each implemented as a struct, with base addr, vector and right
Methods: load(8/16/32)/store(8/16/32)

### Warps
Attributes: several warps, each implemented as a struct, with id, status, pc, amask, reg
Methods: functions to change attributes, all of them

### Scheduler
Attributes: Policies
Methodes: next_warp, that reads all warps and decides, which id is next

### Decoder
Attributes: None
Methodes: decode_instr

### Executor
Attributes: None
Methods: compute register vals, calls load and store etc

### Tracer
Attributes: enable
Methodes: trace_cur_res

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


### Lockstep Required
Lockstep is required, else it's just testing warps isolated and in parallel. There won't be the interesting bugs

For this, the ISS just need's the commited warp_id and the seq_id, so it can start it's warp and the right order and compare both results

Each instruction get's a seq_id so it doesn't matter if add then load or load then add commits, which is important for latency hiding, the reason for GPU
- Plus is, that I can check that each instr is submitted once
- Note store is commited, when written in buffer. From this point it cannot be changed, check for alignment etc is done before buffer

### ISA
Shared memory access is only valid, if barrier was set
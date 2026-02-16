Process = running program

Virtualising the CPU = running one process, stopping, then running another (tim sharing), performance bottleneck as no. of concurrent processes increases

mechanisms ("how") = low level methods that implement a needed piece of functionality e.g. context switch

policies ("which") = algorithms for making some kind of decision within the OS e.g. given a no. of possible programs to run on a CPU, which will the OS run

scheduling poilcy makes ^ decision using historical info, workload knowledge, performance metrics

Context switch = gives OS ability to stop running one program and start running another

machine state = what a program can read or update when it is running e.g. memory + registers

INSTRUCTIONS LIVE IN MEMORY (and data obviously)

Address space = memory a process can access


Program counter / Instruction pointer = which instruction of the program will execute next
Stack pointer + frame pointer  = manages stack


Process states: running (executing instructions), ready (ready to run but not run yet), blocked (performed an operation that makes it not ready to run until another event takes place, e.g. I/O), page 32 for diagram
> Scheduled = ready -> running
> Descheduled = running -> ready


Process list = DS to track state of all processes


Process can be descrived by its state:
> the contents of memory in its address space
> the contents of CPU registers (program counter + stack pointer, etc.)
> info about I/O (e.g. open files)



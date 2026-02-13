### 2026-02-16 | OSTEP: The Illusion of Processes
**Objective:** Finish Chapter 4 & 5 of OSTEP and implement a basic `fork()` experiment.

**Learnings:**
- The difference between a "Program" (static bytes) and a "Process" (living entity).
- How the Kernel uses the Timer Interrupt to regain control (LDE). This is why "Jitter" happens in HFT!

**Struggles:**
- Spent 30 mins wondering why my child process didn't print. Realized I didn't flush `stdout` before the fork. 

**Micro-Wins:**
- Successfully defused Phase 1 of the Binary Bomb during my lunch break.

**Next Steps:**
- Move to Address Spaces (Ch 13) to understand the memory map.
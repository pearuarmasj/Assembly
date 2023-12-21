__asm__ __volatile__ (
        "movl $1, %%eax\n\t"
        "movl %1, %%ebx\n\t"
        "movl $1, %%ecx\n\t"
        "loop_start:\n\t"
        "cmpl %%ebx, %%ecx\n\t"
        "jg loop_end\n\t"
        "imull %%ecx, %%eax\n\t"
        "incl %%ecx\n\t"
        "jmp loop_start\n\t"
        "loop_end:\n\t"
        "movl %%eax, %0\n\t"
        : "=r" (result)
        : "r" (num)
        : "%eax", "%ebx", "%ecx"
    );

    // C/C++ inline assembly code to calculate factorial of num, and store it in result.
    // Using the GCC extended inline assembly syntax
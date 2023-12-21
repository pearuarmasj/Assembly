#include <iostream>
#include <limits>

extern "C" int factorial(int num); // C++ compiler will not mangle the name

int main() {
    int num = 5;
    std::cout << "Enter a number: ";
    std::cin >> num;

    int result = factorial(num);

    std::cout << "Factorial of " << num << " is " << result << std::endl;

    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cin.get();

    return 0;
}

extern "C" int factorial(int num) {
    int result;
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
    return result;
}
#include <stdio.h>

int main() {
#if defined(__x86_64__) || defined(_M_X64)
    printf("Architecture: x86_64 (AMD64)\n");
#elif defined(__i386__) || defined(_M_IX86)
    printf("Architecture: x86 (i386)\n");
#elif defined(__aarch64__)
    printf("Architecture: ARM64 (ARMv8-A)\n");
#elif defined(__arm__)
    printf("Architecture: ARM (ARMv7 or earlier)\n");
#elif defined(__powerpc__) || defined(__ppc__)
    printf("Architecture: PowerPC\n");
#elif defined(__mips__)
    printf("Architecture: MIPS\n");
#else
    printf("Architecture: Unknown\n");
#endif

    return 0;
}

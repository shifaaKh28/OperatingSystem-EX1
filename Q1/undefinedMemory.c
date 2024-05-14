#include <stdio.h>

int main() {
    int *ptr = (int *)0xdeadbeef; // Attempt to read from an undefined memory address
    int value = *ptr; // Dereference the pointer
    printf("Value at address 0xdeadbeef: %d\n", value);
    return 0;
}

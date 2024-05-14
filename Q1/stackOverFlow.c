#include <stdint.h>

void recursive_function(int depth) {
    char array[1024]; // Allocate some space on the stack
    printf("Current depth: %d\n", depth);
    recursive_function(depth + 1); // Recursive call
}

int main() {
    recursive_function(1); // Start the recursion
    return 0;
}
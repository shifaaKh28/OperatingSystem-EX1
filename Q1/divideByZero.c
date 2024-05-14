#include <stdio.h>

int divide_by_zero() {
    int num = 10;
    return num/0; // Division by zero
}

int main() {
    divide_by_zero();
    return 0;
}

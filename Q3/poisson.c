#include <math.h>
#include "poisson.h"

long double poisson_calc(long double lambda, int k) {
    // Calculate P(X=k) using the Poisson probability mass function formula
    long double probability = (long double)exp(-lambda) * powl(lambda, k) / factorial(k);
    return probability;
}

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

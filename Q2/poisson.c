#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error\n");
        return 1;
    }

    // Convert lambda (λ) and k values from command line arguments to float
    long double lambda = strtold(argv[1], NULL);
    int k = atoi(argv[2]);

    // Calculate Poisson probability
    long double probability = poisson_calc(lambda, k);

    printf("P(X=%d) = %.20Lf\n", k, probability);

    return 0;
}

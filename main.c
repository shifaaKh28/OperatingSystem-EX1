#include "poisson.h"

#define VALUES 5

int main(int argc, char *argv[]){

    int k[] = {1, 10, 2, 3, 3};
    int lambda[] = {2, 2, 2, 3, 100};

    for (int i = 0; i < VALUES; i++)
    {
        printf("Run #%d: lambda = %d, k = %d, poisson_calc = %Lf\n", (i + 1), 
        lambda[i], k[i], poisson_calc(lambda[i], k[i]));
    }
    
    return 0;
}
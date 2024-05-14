#include "poisson.h"
#include<stdio.h>

int main(int argc, char *argv[]){

    int k[] = {1, 10, 2, 3, 3};//array for the k values
    int lambda[] = {2, 2, 2, 3, 100};// array for the lambda

    for (int i = 0; i < 5; i++)
    {
        //call the poisson_calc
        printf("%d): lambda = %d, k = %d, poisson_calc = %Lf\n", (i + 1), 
        lambda[i], k[i], poisson_calc(lambda[i], k[i]));
    }
    
    return 0;
}

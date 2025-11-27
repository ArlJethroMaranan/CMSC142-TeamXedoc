#include <stdio.h>
#include <time.h>

#define N 10

int main(void) {
    int nopts[N + 2];
    int option[N + 2][N + 2];
    int k = 14;
    int count = 1;
    int start, move, i, j, candidate;

    clock_t start_time = clock();

    move = start = 0;
    nopts[start] = 1;

    while (nopts[start] > 0) {
        if (nopts[move] > 0) {
            nopts[++move] = 0;

            if (move <= N) {
                int minCandidate;
                if (move == 1) 
                {
                    minCandidate = 1;
                } 
                else 
                {
                    minCandidate = option[move - 1][nopts[move - 1]] + 1;
                }
                for (candidate = N; candidate >= minCandidate; --candidate) {
                    option[move][++nopts[move]] = candidate;
                }
            }
        } 
        else 
        {
            if (move > 1) {
                int a[N], sum=0;
                for (i = 1; i < move; ++i) 
                {
                    sum += option[i][nopts[i]];
                    a[i-1] = option[i][nopts[i]];                       
                }

                if (sum == k){
                    for (j = 0; j < move -1 ; j++) {
                        printf("%d ", a[j]);
                    }
                    printf("\n");
                }
                
            }
            nopts[--move]--;
        }
    }

    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC; // in seconds
    printf("Execution time: %f seconds\n", time_taken);

    return 0;
}

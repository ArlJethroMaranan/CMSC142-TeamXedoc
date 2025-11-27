#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 8

int main(){
    int nopts[N+2];
    int option[N+2][N+2];
    int start, move, i, candidate;

    clock_t start_time = clock();

    move = start = 0;
    nopts[start] = 1;

    while (nopts[start] > 0) {
        if (nopts[move] > 0) {
            nopts[++move] = 0;

            if (move > N) {
                for (i = 1; i < move; i++) {
                    printf("%2i ",option[i][nopts[i]]);
                }
                printf("\n");
            } else {
                for (candidate = N; candidate >= 1; candidate--) {
                    for (i = move - 1; i >= 1; i--) {
                        if (option[i][nopts[i]] == candidate) {
                            break;
                        }
                    }
                    if (!(i >= 1)) {
                        option[move][++nopts[move]] = candidate;
                    }
                }
            }
        }
        else nopts[--move]--;
    }

    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC; // in seconds
    printf("Execution time: %f seconds\n", time_taken);
}



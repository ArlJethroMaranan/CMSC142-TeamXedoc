#include <stdio.h>

#define N 10
#define SUBSET_SIZE 3

int main(void) {
    int nopts[N + 2];
    int option[N + 2][N + 2];
    int subset[SUBSET_SIZE] = {4, 1, 3};
    int k = 25;
    int count = 1;
    int start, move, i, j, m, n, candidate, num, inSubset;
    int temp_sum = 0;

    for (i = 0; i < SUBSET_SIZE; i++){
        temp_sum += subset[i];
    }
    temp_sum = k - temp_sum;

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
                    inSubset = 0;
                    for (m = 0; m < SUBSET_SIZE; m++) {
                        if (subset[m] == candidate) {
                            inSubset = 1;
                            break;
                        }
                    }
                    if (inSubset == 0){
                        option[move][++nopts[move]] = candidate;
                    }
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
                if (sum == temp_sum){
                    for (m = 0; m < SUBSET_SIZE; m++) {
                        printf("%d ", subset[m]);
                    }
                    for (j = 0; j < move -1 ; j++) {
                        printf("%d ", a[j]);
                    }
                    printf("\n");
                }
            }
            nopts[--move]--;
        }
    }

    return 0;
}

#include <stdio.h>

#define N 5

int main(void) {
    int nopts[N + 2];
    int option[N + 2][N + 2];
    int start, move, i, candidate;

    move = start = 0;
    nopts[start] = 1;

    while (nopts[start] > 0) {
        if (nopts[move] > 0) {
            nopts[++move] = 0;

            if (move <= N) {
                int minCandidate;
                if (move == 1) {
                    minCandidate = 1;
                } else {
                    minCandidate = option[move - 1][nopts[move - 1]] + 1;
                }
                for (candidate = N; candidate >= minCandidate; --candidate) {
                    option[move][++nopts[move]] = candidate;
                }
            }
        } else {
            if (move > 1) {
                for (i = 1; i < move; ++i) {
                    printf("%d", option[i][nopts[i]]);
                }
                printf("\n");
            }
            nopts[--move]--;
        }
    }

    return 0;
}

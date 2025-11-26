#include <stdio.h>

#define K 10

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shell(int a[], int n) {
    int gap, j, k;
    for (gap = n / 2; gap >= 1; gap /= 2) {
        for (j = gap; j < n; j++) {
            for (k = j; k > gap - 1; k -= gap) {
                if (a[k - gap] > a[k]) {
                    swap(&a[k - gap], &a[k]);
                } else {
                    break;
                }
            }
        }
    }
}

void fillRowWithBacktrack(const int S[], int rowIndex, int subsetSum[][K + 1]) {
    int upto = rowIndex + 1;
    int nopts[upto + 2];
    int option[upto + 2][upto + 2];
    int start = 0;
    int move = 0;
    int candidate, sum, i;

    for (i = 0; i < upto + 2; ++i) {
        nopts[i] = 0;
    }

    for (i = 0; i < upto + 2; ++i) {
        int j;
        for (j = 0; j < upto + 2; ++j) {
            option[i][j] = 0;
        }
    }

    subsetSum[rowIndex][0] = 1;
    nopts[start] = 1;

    while (nopts[start] > 0) {
        if (nopts[move] > 0) {
            nopts[++move] = 0;

            if (move <= upto) {
                int minCandidate;

                if (move == 1) {
                    minCandidate = 1;
                } else {
                    minCandidate = option[move - 1][nopts[move - 1]] + 1;
                }

                for (candidate = upto; candidate >= minCandidate; --candidate) {
                    option[move][++nopts[move]] = candidate;
                }
            }
        } else {
            if (move > 1) {
                sum = 0;

                for (i = 1; i < move; ++i) {
                    int index = option[i][nopts[i]] - 1;
                    sum += S[index];
                }

                if (sum <= K) {
                    subsetSum[rowIndex][sum] = 1;
                }
            }

            nopts[--move]--;
        }
    }
}

void printSubsetSumMatrix(const int S[], int length, int subsetSum[][K + 1]) {
    int i, j;

    printf("Subset sum matrix:\n    ");
    for (j = 0; j <= K; ++j) {
        printf("%2d ", j);
    }
    printf("\n");

    for (i = 0; i < length; ++i) {
        printf("%d | ", S[i]);

        for (j = 0; j <= K; ++j) {
            printf("%2d ", subsetSum[i][j]);
        }
        printf("\n");
    }
}

void traceOneSubset(const int S[], int length, int subsetSum[][K + 1]) {
    int row = length - 1;
    int col = K;
    int picked[length];
    int pickedCount = 0;

    if (row < 0 || !subsetSum[row][K]) {
        printf("No subset sums to %d.\n", K);
        return;
    }

    while (row >= 0 && col > 0) {
        if (subsetSum[row][col] == 0) {
            --col;
            continue;
        }

        if (row > 0 && subsetSum[row - 1][col] == 1) {
            --row;
            continue;
        }

        picked[pickedCount++] = S[row];
        col -= S[row];
        --row;
    }

    if (col == 0) {
        int i;
        printf("One subset that sums to %d: ", K);
        for (i = 0; i < pickedCount; ++i) {
            printf("%d", picked[i]);
            if (i < pickedCount - 1) {
                printf(" ");
            }
        }
        printf("\n");
    } else {
        printf("No subset sums to %d.\n", K);
    }
}

int main(void) {
    int S[] = {5, 2, 3, 4};
    int length = (int)(sizeof(S) / sizeof(S[0]));
    int subsetSum[length][K + 1];
    int i, j;

    shell(S, length);

    for (i = 0; i < length; ++i) {
        for (j = 0; j <= K; ++j) {
            subsetSum[i][j] = 0;
        }
    }

    for (i = 0; i < length; ++i) {
        fillRowWithBacktrack(S, i, subsetSum);
    }

    printSubsetSumMatrix(S, length, subsetSum);

    traceOneSubset(S, length, subsetSum);

    return 0;
}

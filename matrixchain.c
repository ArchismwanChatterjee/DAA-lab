#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of scalar multiplications
int matrixChainMultiplication(int dims[], int n) {
    int dp[n][n];

    // Initialize the dp array with 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    // Fill the dp array diagonally
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n - 1];
}

int main() {
    int dims[] = {1, 2, 3, 4};
    int n = sizeof(dims) / sizeof(dims[0]);

    int minMultiplications = matrixChainMultiplication(dims, n);
    printf("Minimum number of scalar multiplications: %d\n", minMultiplications);

    return 0;
}
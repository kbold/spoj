/**
 * DP
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

#define MOD 100
#define MAX 101
int A[MAX];
int dp[MAX][MAX];
int sum[MAX][MAX];

int solve(int i, int j) {
    if (dp[i][j] != INT_MAX) return dp[i][j];

    if (i + 1 == j) {
        return A[i] * A[j];
    }

    int &result = dp[i][j];

    for (int k = i; k < j; k++) {
        int localResult = solve(i, k) + solve(k + 1, j) + sum[i][k] * sum[k + 1][j];

        result = min(result, localResult);
    }

    return result;
}

int main() {
    int N;
    while (cin >> N) {

        for (int i = 0; i < N; i++) {
            cin >> A[i];
            sum[i][i] = A[i];
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) dp[i][j] = 0;
                else dp[i][j] = INT_MAX;
            }

            for (int j = i + 1; j < N; j++) {
                sum[i][j] = sum[i][j - 1] + A[j];
                if (sum[i][j] >= MOD) sum[i][j] -= MOD;
            }
        }

        cout << solve(0, N - 1) << endl;
    }

    return 0;
}
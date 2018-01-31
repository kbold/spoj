/**
 * DP
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <climits>

using namespace std;


int main() {
    int T;
    cin >> T;
    while (T--) {
        string A, B;
        cin >> A;
        cin >> B;

        int N = A.length();
        int M = B.length();

        int dp[N + 1][M + 1];
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                if (i == 0) dp[i][j] = j;
                else if (j == 0) dp[i][j] = i;
                else if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
                }
            }
        }

        cout << dp[N][M] << endl;
    }


    return 0;
}
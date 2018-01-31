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
    int K;
    while (cin >> K) {
        if (K == 0) break;
        string A, B;
        cin >> A;
        cin >> B;

        int N = A.length();
        int M = B.length();

        int dp[N + 1][M + 1];
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                dp[i][j] = 0;
                if (i == 0 || j == 0) continue;

                int count = 1;
                while (i - count >= 0 && j - count >= 0 && A[i - count] == B[j - count]) {
                    if (count >= K) {
                        dp[i][j] = max(dp[i][j], count + dp[i - count][j - count]);
                    }
                    count ++;
                }

                dp[i][j] = max(dp[i][j], dp[i-1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
        }

        cout << dp[N][M] << endl;
    }
    return 0;
}
/**
 * DP
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M) {
        if (N == 0 && M == 0) break;

        int yeyenum[N + 1][M + 1];
        int bloggium[N + 1][M + 1];
        int dp[N + 1][M + 1];
        memset(yeyenum, 0, sizeof(yeyenum));
        memset(bloggium, 0, sizeof(bloggium));
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> yeyenum[i][j];
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> bloggium[i][j];
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                yeyenum[i][j] += yeyenum[i][j - 1];
                bloggium[i][j] += bloggium[i - 1][j];

                dp[i][j] = max(dp[i - 1][j] + yeyenum[i][j], dp[i][j - 1] + bloggium[i][j]);
            }
        }

        cout << max(dp[N][M - 1] + bloggium[N][M], dp[N - 1][M] + yeyenum[N][M]) << endl;
    }

    return 0;
}
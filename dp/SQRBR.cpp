/**
 * DP
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <unordered_set>

using namespace std;
#define MAX 40
int dp[MAX][MAX];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        unordered_set<int> s;
        for (int i = 0; i < K; i++) {
            int value;
            cin >> value;
            s.insert(value);
        }

        for (int i = 1; i <= N * 2; i++) {
            for (int j = 0; j <= i; j++) {
                if (i == 1) {
                    dp[i][j] = (j == 1) ? 1 : 0;
                } else {
                    if (s.find(i) != s.end()) {
                        dp[i][j] = (j == 0) ? 0 : dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = dp[i - 1][j + 1] + ((j == 0) ? 0 : dp[i - 1][j - 1]);
                    }
                }
            }
        }
        cout << dp[N * 2][0] << endl;
    }

    return 0;
}
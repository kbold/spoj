/**
 * DP
 */
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    string s;

    while (cin >> s) {
        int N = s.length();
        if (N == 1 && s[0] == '0') break;

        int dp[N + 1];
        dp[0] = 1;
        int prevValue = 0;
        for (int i = 1; i <= N; i++) {
            dp[i] = 0;
            int value = s[i - 1] - '0';
            if (0 < value && value < 10) dp[i] += dp[i - 1];
            int x = prevValue * 10 + value;
            if (i > 1 && 9 < x && x < 27) dp[i] += dp[i - 2];
            prevValue = value;
        }

        cout << dp[N] << endl;
    }

    return 0;
}
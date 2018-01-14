/**
 * Ad-hoc
 */
#include <iostream>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        if (N == -1) break;
        int candies[N];
        int sum = 0;
        for (int i=0;i<N;i++) {
            int value;
            cin >> value;
            candies[i] = value;
            sum += value;
        }

        if (sum % N == 0) {
            int answer = 0;
            int target = sum / N;
            for (int i=0;i<N;i++) {
                if (target > candies[i]) {
                    answer += target - candies[i];
                }
            }
            cout << answer << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
/**
 * Simple Math
 */
#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, x, y;
        cin >> N >> x >> y;
        bool first = true;
        for (int value = 1; value < N; value++) {
            if (value % x == 0 && value % y != 0) {
                if (!first) cout << " ";
                cout << value;
                first = false;
            }
        }
        cout << endl;
    }
    return 0;
}
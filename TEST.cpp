/**
 * Ad-hoc
 */
#include <iostream>
using namespace std;

int main() {
    int value;
    while (cin >> value) {
        if (value == 42) break;
        cout << value << endl;
    }
    return 0;
}
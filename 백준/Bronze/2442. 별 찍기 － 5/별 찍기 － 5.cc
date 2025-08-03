#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= 2 * n - 1; i += 2) {
        int space = (2 * n - 1 - i) / 2;

        cout << string(space, ' ');
        cout << string(i, '*');
        cout << '\n';
    }
}

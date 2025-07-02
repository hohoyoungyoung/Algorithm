#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 3; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int cnt = a + b + c + d;  // 1의 개수

        if (cnt == 0) cout << 'D' << '\n';
        else if (cnt == 1) cout << 'C' << '\n';
        else if (cnt == 2) cout << 'B' << '\n';
        else if (cnt == 3) cout << 'A' << '\n';
        else if (cnt == 4) cout << 'E' << '\n';
    }

    return 0;
}

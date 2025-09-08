#include <iostream>

using namespace std;

bool is_prime(int N) {
    if (N < 2) return false;        // 0,1은 소수 아님
    for (int i = 2; i * i <= N; i++) {
        if (N % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    int ans = 0;

    while (N--) {
        int a;
        cin >> a;
        if (is_prime(a)) { ans++; }
    }

    cout << ans;
}

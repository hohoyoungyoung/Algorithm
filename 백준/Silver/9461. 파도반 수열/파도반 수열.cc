#include <iostream>
using namespace std;

long long dp[101];  // N은 최대 100

void precompute() {
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;
    for (int i = 6; i <= 100; i++) {
        dp[i] = dp[i - 1] + dp[i - 5];
    }
}

int main() {
    int T, N;
    cin >> T;

    precompute();  // 파도반 수열 미리 계산

    while (T--) {
        cin >> N;
        cout << dp[N] << '\n';
    }

    return 0;
}

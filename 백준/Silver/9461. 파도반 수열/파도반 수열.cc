#include <iostream>
#include <vector>
using namespace std;

vector<long long> precompute(int max_n) {
    vector<long long> dp(max_n + 1, 0);  // 1-based indexing을 위해 +1

    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;

    for (int i = 6; i <= max_n; i++) {
        dp[i] = dp[i - 1] + dp[i - 5];
    }

    return dp;
}

int main() {
    int T;
    cin >> T;

    // 문제 조건에서 N ≤ 100이므로 미리 계산
    vector<long long> dp = precompute(100);

    while (T--) {
        int N;
        cin >> N;
        cout << dp[N] << '\n';
    }

    return 0;
}

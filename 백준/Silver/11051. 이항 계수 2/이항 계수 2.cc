#include <iostream>
using namespace std;
const int MOD = 10007;

int dp[1001][1001];

int main() {
    int N, K;
    cin >> N >> K;

    for (int n = 0; n <= N; n++) {
        dp[n][0] = dp[n][n] = 1;
        for (int k = 1; k < n; k++) {
            dp[n][k] = (dp[n-1][k-1] + dp[n-1][k]) % MOD;
        }
    }

    cout << dp[N][K] << '\n';
}

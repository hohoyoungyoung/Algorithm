#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> dp(N+1, 0);
    vector<int> prev(N+1, 0);

    dp[1] = 0;
    for (int i=2; i<=N; i++) {
        // 1을 빼는 경우
        dp[i] = dp[i-1] + 1;
        prev[i] = i-1;

        if (i % 2 == 0 && dp[i] > dp[i/2] + 1) {
            dp[i] = dp[i/2] + 1;
            prev[i] = i/2;
        }
        if (i % 3 == 0 && dp[i] > dp[i/3] + 1) {
            dp[i] = dp[i/3] + 1;
            prev[i] = i/3;
        }
    }

    // 최소 연산 횟수
    cout << dp[N] << '\n';

    // 경로 복원
    int cur = N;
    while (cur > 0) {
        cout << cur << ' ';
        if (cur == 1) break;
        cur = prev[cur];
    }
}

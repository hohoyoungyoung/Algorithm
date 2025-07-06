#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> dp(N + 1);  // 벡터로 동적 배열 선언

    if (N >= 1) dp[1] = 1;
    if (N >= 2) dp[2] = 2;

    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    }

    cout << dp[N] << endl;
    return 0;
}

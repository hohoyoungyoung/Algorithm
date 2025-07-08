#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> dp(N);

    // 입력
    for (int i = 0; i < N; i++) {
        dp[i].resize(i + 1);  // 삼각형 구조
        for (int j = 0; j <= i; j++) {
            cin >> dp[i][j];
        }
    }

    // DP 계산
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp[i][j] += dp[i - 1][j];
            } else if (j == i) {
                dp[i][j] += dp[i - 1][j - 1];
            } else {
                dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
            }
        }
    }

    // 마지막 줄에서 최대값 출력
    int result = *max_element(dp[N - 1].begin(), dp[N - 1].end());
    cout << result << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<long long> dp(K + 1, 0);  // 무게별 최대 가치 저장
    int weight, value;

    for (int i = 0; i < N; i++) {
        cin >> weight >> value;

        for (int j = K; j >= weight; j--) {
            dp[j] = max(dp[j], dp[j - weight] + value);
        }
    }

    cout << dp[K] << '\n';
    return 0;
}

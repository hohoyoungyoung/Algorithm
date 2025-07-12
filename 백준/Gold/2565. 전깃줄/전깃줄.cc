#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LIS(const vector<int>& seq) {
    int n = seq.size();
    vector<int> dp(n, 1);  // 모두 1로 초기화

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (seq[j] < seq[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> wire(N);
    for (int i = 0; i < N; ++i) {
        cin >> wire[i].first >> wire[i].second;
    }

    // A 기준 정렬
    sort(wire.begin(), wire.end());

    // B만 추출
    vector<int> b_values(N);
    for (int i = 0; i < N; ++i) {
        b_values[i] = wire[i].second;
    }

    int result = N - LIS(b_values);
    cout << result << '\n';

    return 0;
}

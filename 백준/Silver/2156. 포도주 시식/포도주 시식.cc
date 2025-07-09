#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> wine(N);
    for (int i = 0; i < N; i++) {
        cin >> wine[i];
    }

    if (N == 1) {
        cout << wine[0] << '\n';
        return 0;
    }

    if (N == 2) {
        cout << wine[0] + wine[1] << '\n';
        return 0;
    }

    vector<int> dp(N);
    dp[0] = wine[0];
    dp[1] = wine[0] + wine[1];
    dp[2] = max(wine[0] + wine[1], max(wine[0] + wine[2], wine[1] + wine[2]));

    for (int i = 3; i < N; i++) {
        dp[i] = max(
            dp[i - 1],
            max(dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i])
        );
    }

    cout << dp[N - 1] << '\n';
    return 0;
}

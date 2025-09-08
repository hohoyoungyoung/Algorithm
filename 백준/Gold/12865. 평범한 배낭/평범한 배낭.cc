#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int N, K;

    cin >> N >> K;
    vector<int> dp(K+1,0);
    vector<pair<int,int>> store(N,{0,0});

    for (int i=0; i<N; i++) {
        int a, b;
        cin >> a >> b;
        store[i] = {a, b};
    }

    sort(store.begin(), store.end());

    for (auto check: store) {
        int w = check.first; //무게
        int v = check.second; //가치

        for (int i=K; i>=w; i--) {
            dp[i] = max(dp[i-w] + v, dp[i]);
        }
    }
    cout << dp[K];
}

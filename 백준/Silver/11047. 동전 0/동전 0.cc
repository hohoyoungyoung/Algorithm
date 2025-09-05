#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i=0; i<N; i++) cin >> a[i];

    int ans = 0;
    for (int i=N-1; i>=0 && K>0; i--) {
        if (a[i] <= K) {
            ans += K / a[i];
            K %= a[i];
        }
    }
    cout << ans << '\n';
}

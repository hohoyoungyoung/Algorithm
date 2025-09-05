#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K;
    cin >> N >> K;

    vector<long long> a(N);
    for (int i=0; i<N; i++) cin >> a[i];

    long long ans = 0;
    for (int i=N-1; i>=0 && K>0; i--) {
        if (a[i] <= K) {
            ans += K / a[i];
            K %= a[i];
        }
    }
    cout << ans << '\n';
}

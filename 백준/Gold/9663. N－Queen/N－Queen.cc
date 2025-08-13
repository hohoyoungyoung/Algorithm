#include <bits/stdc++.h>
using namespace std;

int N;
long long ans = 0;
vector<bool> col_used;       // 열 사용 여부
vector<bool> diag1_used;     // ↘ 대각선 (r + c)
vector<bool> diag2_used;     // ↙ 대각선 (r - c + N - 1)

void dfs(int r) {
    if (r == N) {            // N개의 행을 모두 배치 완료
        ans++;
        return;
    }
    for (int c = 0; c < N; ++c) {
        if (col_used[c] || diag1_used[r + c] || diag2_used[r - c + N - 1]) continue;
        col_used[c] = diag1_used[r + c] = diag2_used[r - c + N - 1] = true;
        dfs(r + 1);
        col_used[c] = diag1_used[r + c] = diag2_used[r - c + N - 1] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    col_used.assign(N, false);
    diag1_used.assign(2 * N - 1, false);
    diag2_used.assign(2 * N - 1, false);

    dfs(0);
    cout << ans << '\n';
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, R;
int cnt = 1;
vector<vector<int>> adj;
vector<int> visited;

void dfs(int start) {
    visited[start] = cnt;
    for (auto num : adj[start]) {
        if (visited[num] == 0) {
            cnt++;
            dfs(num);  // 세미콜론 추가!
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> R;

    adj.resize(N + 1);
    visited.resize(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // 내림차순 정렬
    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end(), greater<int>());
    }

    dfs(R);

    for (int i = 1; i <= N; i++) {
        cout << visited[i] << '\n';
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, R;
    cin >> N >> M >> R;

    vector<vector<int>> adj(N + 1);
    vector<int> visited(N + 1, 0);
    int cnt = 1;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    queue<int> q;
    q.push(R);
    visited[R] = cnt;

    while (!q.empty()) {
        int num = q.front();
        q.pop();
        for (int i : adj[num]) {
            if (visited[i] == 0) {
                cnt++;
                visited[i] = cnt;
                q.push(i);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << visited[i] << '\n';
    }

    return 0;
}

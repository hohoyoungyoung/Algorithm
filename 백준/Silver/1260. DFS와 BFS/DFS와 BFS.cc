#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<vector<int>> adj;
vector<bool> visited;
vector<bool> visited2;
vector<int> ans1;
vector<int> ans2;

void dfs(int m) {
    visited[m] = true;
    ans1.push_back(m);
    for (int i : adj[m]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

void bfs(int m) {
    queue<int> q;
    q.push(m);
    visited2[m] = true;
    ans2.push_back(m);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i : adj[cur]) {
            if (!visited2[i]) {
                visited2[i] = true;
                ans2.push_back(i);
                q.push(i);
            }
        }
    }
}

int main() {
    cin >> N >> M >> V;

    adj.resize(N + 1);
    visited.resize(N + 1, false);
    visited2.resize(N + 1, false);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= N; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(V);
    for (int i = 0; i < ans1.size(); ++i) {
        cout << ans1[i];
        if (i != ans1.size() - 1) cout << " ";
    }
    cout << "\n";

    bfs(V);
    for (int i = 0; i < ans2.size(); ++i) {
        cout << ans2[i];
        if (i != ans2.size() - 1) cout << " ";
    }
    cout << "\n";

    return 0;
}

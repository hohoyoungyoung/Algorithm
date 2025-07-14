#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> ans;
int cnt = 1;

void dfs(int node) {
    ans[node] = cnt;
    for (auto neighbor : adj[node]) {
        if (ans[neighbor] == 0) {
            cnt++;
            dfs(neighbor);
        }
    }
}

int main() {
    int N, M, R;
    cin >> N >> M >> R;

    adj.resize(N + 1);
    ans.resize(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(R);

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> num_list(n + 1);
        vector<vector<int>> adj(n + 1);
        vector<int> indegree(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            cin >> num_list[i];
        }

        // 간선 생성
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int a = num_list[i];
                int b = num_list[j];
                adj[a].push_back(b);
                indegree[b]++;
            }
        }

        int m;
        cin >> m;

        // 상대 순위 바뀐 쌍 반영
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;

            // 원래 a -> b 였던 경우
            auto it = find(adj[a].begin(), adj[a].end(), b);
            if (it != adj[a].end()) {
                adj[a].erase(it);
                adj[b].push_back(a);
                indegree[b]--;
                indegree[a]++;
            } else {
                // 원래 b -> a 였던 경우
                auto it2 = find(adj[b].begin(), adj[b].end(), a);
                if (it2 != adj[b].end()) {
                    adj[b].erase(it2);
                    adj[a].push_back(b);
                    indegree[a]--;
                    indegree[b]++;
                }
            }
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;
        bool certain = true;
        bool cycle = false;

        for (int i = 0; i < n; i++) {
            if (q.empty()) {
                cycle = true;
                break;
            }
            if (q.size() > 1) {
                certain = false;
            }

            int now = q.front();
            q.pop();
            result.push_back(now);

            for (int nxt : adj[now]) {
                indegree[nxt]--;
                if (indegree[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }

        if (cycle) {
            cout << "IMPOSSIBLE\n";
        } else if (!certain) {
            cout << "?\n";
        } else {
            for (int i = 0; i < result.size(); i++) {
                cout << result[i];
                if (i != result.size() - 1) cout << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}

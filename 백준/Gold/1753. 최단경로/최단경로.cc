#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int V, E, K;
vector<vector<pair<int, int>>> adj;
vector<int> dist;  // ✅ 'distance' → 'dist'로 이름 변경

void dijkstra(int start) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d > dist[now]) continue;

        for (auto& edge : adj[now]) {
            int nxt = edge.first;
            int cost = edge.second;
            int new_dist = d + cost;

            if (new_dist < dist[nxt]) {
                dist[nxt] = new_dist;
                pq.push({new_dist, nxt});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> V >> E >> K;
    adj.resize(V + 1);
    dist.assign(V + 1, INF);  

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    dijkstra(K);

    for (int i = 1; i <= V; ++i) {
        if (dist[i] == INF) {
            cout << "INF\n";
        } else {
            cout << dist[i] << '\n';
        }
    }

    return 0;
}

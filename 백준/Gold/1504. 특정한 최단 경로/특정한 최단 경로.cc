#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int N, E;
vector<vector<pair<int, int>>> adj;

vector<int> dijkstra(int start) {
    vector<int> distance(N + 1, INF);
    distance[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist > distance[node]) continue;

        for (auto& [next, cost] : adj[node]) {
            if (distance[next] > distance[node] + cost) {
                distance[next] = distance[node] + cost;
                pq.push({distance[next], next});
            }
        }
    }

    return distance;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> E;
    adj.resize(N + 1);

    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<int> dist1 = dijkstra(1);
    vector<int> dist_v1 = dijkstra(v1);
    vector<int> dist_v2 = dijkstra(v2);

    long long path1 = 1LL * dist1[v1] + dist_v1[v2] + dist_v2[N];
    long long path2 = 1LL * dist1[v2] + dist_v2[v1] + dist_v1[N];

    long long result = min(path1, path2);
    cout << (result >= INF ? -1 : result) << '\n';

    return 0;
}

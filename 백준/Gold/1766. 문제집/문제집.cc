#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);
    vector<int> indegree(N + 1, 0);

    // 간선 정보 입력
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    // 우선순위 큐 (작은 숫자가 먼저 나오는 min-heap)
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> result;

    while (!pq.empty()) {
        int now = pq.top();
        pq.pop();
        result.push_back(now);

        for (int nxt : adj[now]) {
            indegree[nxt]--;
            if (indegree[nxt] == 0) {
                pq.push(nxt);
            }
        }
    }

    // 출력
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << " ";
    }
    cout << "\n";

    return 0;
}

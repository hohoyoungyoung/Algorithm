#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);     // 인접 리스트
    vector<int> indegree(N + 1, 0);     // 진입 차수 배열
    vector<int> result;                 // 결과 저장
    queue<int> q;

    // 간선 입력
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);   // a → b
        indegree[b] += 1;      // b의 진입 차수 증가
    }

    // 진입 차수 0인 노드 큐에 삽입
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // 위상 정렬
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        result.push_back(now);

        for (int nxt : adj[now]) {
            indegree[nxt] -= 1;
            if (indegree[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}

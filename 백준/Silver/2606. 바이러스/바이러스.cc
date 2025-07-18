#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>  // accumulate 사용을 위해 필요

using namespace std;

int max_num;
int N;
vector<vector<int>> adj;
vector<int> visited;

void dfs(int s) {
    if (!visited[s]) {
        visited[s] = 1; // 방문 처리
        for (auto line : adj[s]) {
            dfs(line);
        }
    }
}

int main() {
    cin >> max_num;
    cin >> N;

    adj.resize(max_num + 1);
    visited.resize(max_num + 1, 0);

    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    // 방문한 컴퓨터 수 (1번 제외)
    int infected = accumulate(visited.begin(), visited.end(), 0) - 1;

    cout << infected << endl;

    return 0;
}

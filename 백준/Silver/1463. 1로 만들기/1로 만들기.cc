// DP 문제지만 BFS로 풀어보기

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<int> visited;
queue<int> que;
vector<int> dist;

int main() {
    cin >> N;

    visited.resize(N+1, 0);
    dist.resize(N+1, 0);
    visited[N] = 1;
    dist[N] = 0;

    que.push(N);

    while (!que.empty()) {
    int sub = que.front();
    que.pop();
    
    if (sub%3 == 0 && visited[sub/3]==0) {
        que.push(sub/3);
        visited[sub/3] = 1;
        dist[sub/3] = dist[sub] + 1;
    }
    if (sub%2 == 0 && visited[sub/2]==0) {
        que.push(sub/2);
        visited[sub/2] = 1;
        dist[sub/2] = dist[sub] + 1;

    }
    if (sub >1 && visited[sub-1]==0) {
    que.push(sub-1);
    visited[sub-1] = 1;
    dist[sub-1] = dist[sub] + 1;
    }
    }
    cout << dist[1];

}
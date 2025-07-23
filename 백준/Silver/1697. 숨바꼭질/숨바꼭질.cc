#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;

int main() {
    cin >> N >> K;

    vector<bool> visited(100001, false);
    queue<pair<int, int>> q;  // (현재 위치, 시간)
    q.push({N, 0});
    visited[N] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int time = q.front().second;
        q.pop();

        if (x == K) {
            cout << time << '\n';
            return 0;
        }

        for (int next : {x - 1, x + 1, x * 2}) {
            if (next >= 0 && next < 100001 && !visited[next]) {
                visited[next] = true;
                q.push({next, time + 1});
            }
        }
    }

    return 0;
}

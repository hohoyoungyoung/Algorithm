#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N, M;
vector<vector<int>> maps;
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

void bfs(int i, int j) {
    queue<pair<int, int>> q; 
    q.push({i, j});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];  
            int ny = y + dy[k];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (maps[nx][ny] == 0) continue;

            if (maps[nx][ny] == 1) {
                maps[nx][ny] = maps[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> N >> M;
    maps.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            maps[i][j] = row[j] - '0';  // 문자 '1' → 숫자 1
        }
    }

    bfs(0, 0);

    cout << maps[N - 1][M - 1] << '\n';
    return 0;
}

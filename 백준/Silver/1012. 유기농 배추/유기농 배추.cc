#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, M, N, K;
vector<vector<int>> maps;
vector<vector<int>> visited;
vector<pair<int, int>> direction = {{-1,0}, {0,-1}, {1,0}, {0,1}};

void bfs(int row, int col) {
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = 1;

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (auto [dr, dc] : direction) {
            int nr = r + dr;
            int nc = c + dc;
            if (0 <= nr && nr < N && 0 <= nc && nc < M) {
                if (maps[nr][nc] == 1 && visited[nr][nc] == 0) {
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }
}

int main() {
    cin >> T;

    while (T--) {
        cin >> M >> N >> K;
        maps.assign(N, vector<int>(M, 0));
        visited.assign(N, vector<int>(M, 0));

        for (int i = 0; i < K; ++i) {
            int x, y;
            cin >> x >> y;
            maps[y][x] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (maps[i][j] == 1 && visited[i][j] == 0) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}

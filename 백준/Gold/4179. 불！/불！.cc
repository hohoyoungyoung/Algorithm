#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int R, C;

int main() {
    cin >> R >> C;
    vector<string> maze(R);
    vector<vector<int>> fire(R, vector<int>(C, 0));  // 0 = 불 미도달, >0 = 시간, -1 = 벽
    vector<vector<int>> move(R, vector<int>(C, 0));  // 0 = 미방문, >0 = 시간, -1 = 벽
    vector<pair<int,int>> direction = {{0,1},{1,0},{-1,0},{0,-1}};

    queue<pair<int, int>> q1; // fire
    queue<pair<int, int>> q2; // jihun

    for (int i = 0; i<R; i++) cin >> maze[i];

    int sr=-1, sc=-1;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (maze[i][j] == 'F') {
                q1.push({i,j});
                fire[i][j] = 1;           // 시작시간 1
            } else if (maze[i][j] == 'J') {
                q2.push({i,j});
                move[i][j] = 1;           // 시작시간 1
                sr = i; sc = j;
            } else if (maze[i][j] == '#') {
                fire[i][j] = -1;
                move[i][j] = -1;
            }
        }
    }

    // 시작이 가장자리면 바로 1
    if (sr == 0 || sc == 0 || sr == R-1 || sc == C-1) {
        cout << 1 << '\n';
        return 0;
    }

    // 불 BFS
    while (!q1.empty()) {
        auto [dx, dy] = q1.front(); q1.pop();
        for (auto d: direction) {
            int nx = dx + d.first;
            int ny = dy + d.second;

            if (nx<0||nx>=R||ny<0||ny>=C) continue;
            if (maze[nx][ny] == '#') continue;
            if (fire[nx][ny] != 0) continue;           // 0(미도달)일 때만 갱신

            fire[nx][ny] = fire[dx][dy] + 1;
            q1.push({nx, ny});
        }
    }

    // 지훈 BFS
    while (!q2.empty()) {
        auto [dx, dy] = q2.front(); q2.pop();
        for (auto d: direction) {
            int nx = dx + d.first;
            int ny = dy + d.second;

            if (nx<0||nx>=R||ny<0||ny>=C) continue;
            if (maze[nx][ny] == '#') continue;
            if (move[nx][ny] != 0) continue;           // 0(미방문)만

            int nt = move[dx][dy] + 1;

            // 불이 실제 도달하는 칸(>0)이고, 불 시간이 지훈 새 시간 이하이면 못감
            if (fire[nx][ny] != 0 && fire[nx][ny] <= nt) continue;

            move[nx][ny] = nt;

            if (nx == 0 || ny == 0 || nx == R-1 || ny == C-1) {
                cout << move[nx][ny] << '\n';          // edge 도착 시간 그대로 출력
                return 0;
            }

            q2.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}

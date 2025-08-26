#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int N,M;

struct CCTV {
    int type, y, x;
};
vector<CCTV> cctvs;


int dy[4] = {0,1,-1,0}; // 0:오른쪽(x+), 1:아래(y+), 2:위(y-), 3:왼쪽(x-)
int dx[4] = {1,0,0,-1};

vector<vector<vector<int>>> cctv_dirs =  {
    {}, // 0번 CCTV 없음
    { {0}, {1}, {2}, {3} },
    { {0,3}, {1,2} },
    { {2,0}, {0,1}, {1,3}, {3,2} },
    { {3,2,0}, {2,0,1}, {0,1,3}, {1,3,2} },
    { {0,1,2,3} }
};

int answer = 65;

vector<vector<int>> board;
vector<vector<int>> cctv_loc;

void watch_line(vector<vector<int>>& g, int y, int x, int d) {
    int ny = y + dy[d], nx = x + dx[d];
    while (0 <= ny && ny < N && 0 <= nx && nx < M){
        if (g[ny][nx] == 6) break;
        if (g[ny][nx] == 0) g[ny][nx] = 7;
        ny += dy[d]; nx += dx[d];
    }
}

void dfs(int idx, vector<vector<int>> g){
    if (idx == (int)cctvs.size()) {
        int blind = 0;
        for (int i=0;i<N;i++) for (int j=0;j<M;j++) if (g[i][j]==0) blind++;
        answer = min(answer, blind);
        return;
    }

    auto [type, y, x] = cctvs[idx];
    for (auto& dirs : cctv_dirs[type]) {
        auto ng = g;
        for (int d : dirs) watch_line(ng, y, x, d);
        dfs(idx+1, move(ng));
    }
}


int main() {
    cin >> N >> M;
    board.resize(N, vector<int>(M));

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> board[i][j];
            if (1 <= board[i][j] && board[i][j] <= 5) {
                cctvs.push_back({board[i][j], i, j});
            }
        }
    }

    dfs(0, board);
    cout << answer << '\n';
    return 0;
}
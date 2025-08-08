#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> box(M, vector<int>(N));
    queue<pair<int,int>> q;
    vector<pair<int,int>> direction = {{0,1},{1,0},{-1,0},{0,-1}};

    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            int tomato;
            cin >> tomato;
            box[i][j] = tomato;
            if (tomato == 1) {
                q.push({i, j});
            }

        }
    }

    while (!q.empty()) {
        pair<int,int> curr = q.front();
        q.pop();
        
        int dx = curr.first;
        int dy = curr.second;

        for (auto i:direction) {
            int nx = dx + i.first;
            int ny = dy + i.second;

            if (nx>=0 && nx<M && ny>=0 && ny<N) {
                if (box[nx][ny] == 0) {
                    box[nx][ny] = box[dx][dy] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    int max_day = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (box[i][j] == 0) {
                cout << -1 << endl;
                return 0;
            }
            max_day = max(max_day, box[i][j]);
        }
    }

    cout << max_day - 1 << endl;
    return 0;
}

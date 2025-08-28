#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
vector<vector<int>> board;

// 시계 방향 90도 회전
vector<vector<int>> rotate90(const vector<vector<int>>& s) {
    int rows = s.size();
    int cols = s[0].size();
    vector<vector<int>> new_vec(cols, vector<int>(rows, 0));

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            new_vec[j][rows-1-i] = s[i][j];
        }
    }
    return new_vec;
}

// 들어갈 수 있는지 확인
bool can_place(int x, int y, const vector<vector<int>>& s) {
    int n = board.size(), m = board[0].size();
    int r = s.size(), c = s[0].size();
    if (x<0 || y<0 || x+r>n || y+c>m) return false;

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (s[i][j] && board[x+i][y+j]) return false;
        }
    }
    return true;
}

// 스티커 붙이기
void apply(int x, int y, const vector<vector<int>>& s) {
    int r = s.size(), c = s[0].size();
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (s[i][j]) board[x+i][y+j] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    board.assign(N, vector<int>(M, 0));

    for (int k=0; k<K; k++) {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> sticker(R, vector<int>(C));

        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                cin >> sticker[i][j];
            }
        }

        bool placed = false;
        for (int rot=0; rot<4 && !placed; rot++) {
            int r = sticker.size(), c = sticker[0].size();
            for (int x=0; x<=N-r && !placed; x++) {
                for (int y=0; y<=M-c && !placed; y++) {
                    if (can_place(x, y, sticker)) {
                        apply(x, y, sticker);
                        placed = true;
                    }
                }
            }
            if (!placed) sticker = rotate90(sticker);
        }
    }

    int ans = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (board[i][j]) ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}

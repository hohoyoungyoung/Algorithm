#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> moves = {
        {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
        {1, 2}, {2, 1}, {2, -1}, {1, -2}
    };

    for (int i = 0; i < N; i++) {
        int I;
        cin >> I;
        int start_row, start_col, end_row, end_col;
        cin >> start_row >> start_col >> end_row >> end_col;

        if (start_row == end_row && start_col == end_col) {
            cout << 0 << '\n';
            continue;
        }

        vector<vector<int>> maps(I, vector<int>(I, 0));
        queue<pair<int, int>> q;
        q.push({start_row, start_col});
        bool found = false;

        while (!q.empty() && !found) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (auto [dr, dc] : moves) {
                int nrow = row + dr;
                int ncol = col + dc;

                if (nrow >= 0 && nrow < I && ncol >= 0 && ncol < I && maps[nrow][ncol] == 0) {
                    maps[nrow][ncol] = maps[row][col] + 1;

                    if (nrow == end_row && ncol == end_col) {
                        cout << maps[nrow][ncol] << '\n';
                        found = true;
                        break;
                    }

                    q.push({nrow, ncol});
                }
            }
        }
    }

    return 0;
}

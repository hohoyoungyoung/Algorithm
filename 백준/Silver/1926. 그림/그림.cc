#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> paper(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> paper[i][j];

    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}}; // 상하좌우
    int pictureCount = 0;
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (paper[i][j] == 1) {
                pictureCount++;
                int area = 1;

                queue<pair<int,int>> q;
                q.push({i, j});
                paper[i][j] = -1;  // 방문 처리

                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (auto d : dir) {
                        int nx = x + d.first;
                        int ny = y + d.second;

                        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                            if (paper[nx][ny] == 1) {
                                q.push({nx, ny});
                                paper[nx][ny] = -1;
                                area++;
                            }
                        }
                    }
                }

                maxArea = max(maxArea, area);
            }
        }
    }

    cout << pictureCount << '\n';
    cout << maxArea << '\n';
}

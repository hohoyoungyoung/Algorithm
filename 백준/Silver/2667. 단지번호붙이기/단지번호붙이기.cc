#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int N;
int cnt;
vector<string> maps;
vector<int> result;
vector<vector<int>> visited;
vector<pair<int, int>> direction = {{0,1}, {1,0}, {-1,0}, {0,-1}};

void dfs(int x, int y) {

    for (auto dir: direction) {
        int nx = x + dir.first;
        int ny = y + dir.second;

        if (0 <= nx && nx < N && 0 <= ny && ny < N && maps[nx][ny] == '1' && visited[nx][ny] == 0)
        {
            visited[nx][ny] = 1;
            dfs(nx, ny);
            cnt++;
        }
    }

}


int main() {
    cin >> N;
    visited.resize(N, vector<int>(N,0));

    for (int i=0; i<N; i++) {
        string a;
        cin >> a;
        maps.push_back(a); 
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            
            if (visited[i][j] == 0 && maps[i][j] == '1') {
                cnt = 1;
                visited[i][j] = 1;
                dfs(i, j);
            result.push_back(cnt);
            }
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << '\n';

    for (int i=0; i<result.size(); i++) {
        cout << result[i] << '\n';
    }


}
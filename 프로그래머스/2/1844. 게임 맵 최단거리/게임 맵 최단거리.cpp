// #include<vector>
// #include<iostream>
// #include<queue>
// #include <algorithm>
// #include <utility>
#include <bits/stdc++.h>

using namespace std;


int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    vector<int> dir_x = {1, -1, 0, 0};
    vector<int> dir_y = {0, 0, 1, -1};
    vector<vector<int>> visited(maps.size(), vector<int>(maps[0].size(), 0));
    queue<pair<int,int>> que;
    
    que.push({0,0});
    
    while (!que.empty()) {
        auto [dx, dy] = que.front();
        que.pop();
        
        for (int i=0; i<4; i++) {
        if (dx + dir_x[i] >= 0 && dx + dir_x[i] < maps.size() && dy + dir_y[i] >= 0 && dy + dir_y[i] < maps[0].size() && maps[dx + dir_x[i]][dy+dir_y[i]] == 1 && visited[dx+dir_x[i]][dy+dir_y[i]] == 0){
        int nx = dx + dir_x[i];
        int ny = dy + dir_y[i];
        visited[nx][ny] = visited[dx][dy] + 1;
        
        if (nx == maps.size()-1 && ny == maps[0].size()-1) return visited[nx][ny]+1;
        que.push({nx, ny});
        }
        }
    }
    

    return -1;
}
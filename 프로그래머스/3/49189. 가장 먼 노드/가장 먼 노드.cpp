#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    
    vector<vector<int>> adj(n+1);
    
    for (auto vect: edge) {
        int a = vect[0];
        int b = vect[1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    queue<int> que;
    vector<int> dist(n+1, 0);
    que.push({1});
    
    while (!que.empty()) {
        int num = que.front();
        que.pop();
        
        for (auto i: adj[num]) {
            if (dist[i] == 0 && i != 1) {
                dist[i] = dist[num]+1;
                que.push(i);
            }
            
        }
    }
    
    int ans = 0;
    
    int max_num = *max_element(dist.begin(), dist.end());
    
    for (int i=1; i<n+1; i++) {
        if (dist[i] == max_num) ans++;
    }
    
    return ans;
    
}
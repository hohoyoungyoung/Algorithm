#include <vector>
#include <iostream>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    vector<int> chae(N+1, 0);
    
    
    for (int i=2; i*i<=N; i++) {
        if (chae[i] == 1) continue;
        for (int j=2; i*j < N+1; j++) {
            chae[i*j] = 1;
        }
    }

    for (int i=M; i<N+1; i++) {
        if (i==1) continue;
        if (chae[i] == 0) cout << i << '\n';
    }
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    vector<int> chae(N+1, 0);  // 0=소수 후보, 1=합성수

    chae[0] = chae[1] = 1; // 0,1은 소수 아님

    for (int i = 2; i * i <= N; i++) {
        if (chae[i] == 0) { // 아직 소수라면
            for (int j = 2 * i; j <= N; j += i) {
                chae[j] = 1; // 배수는 합성수로 마킹
            }
        }
    }

    for (int i = M; i <= N; i++) {
        if (chae[i] == 0) cout << i << '\n';
    }

    return 0;
}

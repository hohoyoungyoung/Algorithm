#include <iostream>
#include <vector>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N,M;

    cin >> N >> M;

    vector<int> num(N+1, 0);
    vector<int> presum(N+1, 0);

    for (int i=1; i<N+1; i++) {
        cin >> num[i];
        presum[i] = num[i] + presum[i-1];
    }

    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;

        cout << presum[b] - presum[a-1] << '\n';
    }
}
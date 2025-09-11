#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // C I/O와 분리
    cin.tie(nullptr);            // cin/cout 묶음 해제

    int N, M;
    cin >> N;

    vector<int> store(N);
    for (int i = 0; i < N; i++) {
        cin >> store[i];
    }

    sort(store.begin(), store.end());

    cin >> M;
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;

        auto it = upper_bound(store.begin(), store.end(), a);
        if (it != store.begin() && *(it - 1) == a) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}

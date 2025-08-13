#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int N, S;
int ans = 0;

void backtrack(int i, int sum) {
    // 1. 종료 조건: 모든 원소를 다 결정했을 때
    if (i == N) {
        if (sum == S) ans++;
        return;
    }

    // 2. 현재 원소를 포함하는 경우
    backtrack(i + 1, sum + arr[i]);

    // 3. 현재 원소를 포함하지 않는 경우
    backtrack(i + 1, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    backtrack(0, 0);

    // 공집합 제외
    if (S == 0) ans--;

    cout << ans << '\n';
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int low = min(A, B);
    int high = max(A, B);
    int C = high - low;

    if (C <= 1) {
        cout << 0 << '\n';  // 사이에 수 없음
        return 0;
    }

    vector<int> vec(C - 1);

    cout << C - 1 << '\n';

    for (int i = low + 1; i < high; i++) {
        vec[i - low - 1] = i;
    }

    // 정렬은 이미 오름차순이지만 요구되면 유지
    sort(vec.begin(), vec.end());

    for (auto i : vec) {
        cout << i << ' ';
    }

    return 0;
}

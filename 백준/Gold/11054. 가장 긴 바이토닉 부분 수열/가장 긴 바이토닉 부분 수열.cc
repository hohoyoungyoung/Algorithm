#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> inc(N, 1); // 증가 수열 길이 초기값 1
    vector<int> dec(N, 1); // 감소 수열 길이 초기값 1

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // LIS: 증가하는 부분 수열
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                inc[i] = max(inc[i], inc[j] + 1);
            }
        }
    }

    // LDS: 감소하는 부분 수열
    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j > i; j--) {
            if (A[j] < A[i]) {
                dec[i] = max(dec[i], dec[j] + 1);
            }
        }
    }

    int max_len = 0;
    for (int i = 0; i < N; i++) {
        max_len = max(max_len, inc[i] + dec[i] - 1);
    }

    cout << max_len << endl;
    return 0;
}

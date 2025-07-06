#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;

    long long low = min(A, B);
    long long high = max(A, B);
    long long C = high - low;

    if (C <= 1) {
        cout << 0 << '\n';
        return 0;
    }

    vector<long long> vec(C - 1);

    cout << C - 1 << '\n';

    for (long long i = low + 1; i < high; i++) {
        vec[i - low - 1] = i;
    }

    for (auto i : vec) {
        cout << i << ' ';
    }

    return 0;
}

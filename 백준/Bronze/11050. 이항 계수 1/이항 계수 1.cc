#include <iostream>
using namespace std;

long long fac(int n) {
    if (n == 0 || n == 1) return 1;
    return n * fac(n - 1);
}

int main() {
    int N, K;
    cin >> N >> K;
    
    cout << fac(N) / (fac(N-K) * fac(K)) << '\n';
}

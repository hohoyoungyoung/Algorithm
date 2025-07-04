#include <iostream>
using namespace std;

// dp[a][b][c] 값을 저장할 3차원 배열
int dp[21][21][21];

int w(int a, int b, int c) {
    // 기저 조건
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;

    // 20 초과는 20으로 고정
    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);

    // 이미 계산된 값이 있다면 그 값을 반환
    if (dp[a][b][c] != 0)
        return dp[a][b][c];

    // 점화식 계산 및 저장
    if (a < b && b < c)
        dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else
        dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);

    return dp[a][b][c];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1)
            break;

        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }

    return 0;
}

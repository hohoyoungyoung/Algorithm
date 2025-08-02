#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int N, F;
    cin >> N >> F;

    // N의 앞자리 그대로 두고, 뒤 두 자리를 00으로 바꿈
    N = (N / 100) * 100;

    // 뒤 두 자리 중 가장 작은 F로 나누어 떨어지는 값 찾기
    while (N % F != 0) {
        N++;
    }

    // 끝 두 자리를 두 자리로 출력 (예: 03이면 03으로 출력)
    cout << setw(2) << setfill('0') << (N % 100) << '\n';
}

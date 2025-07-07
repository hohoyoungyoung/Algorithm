#include <iostream>
#include <string>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    string D = to_string(A * B * C);

    int arr[10] = {0};  // 0으로 초기화

    for (auto i : D) {
        arr[i - '0']++;  // 문자를 숫자로 변환
    }

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}

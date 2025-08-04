#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string num;
    cin >> num;

    vector<int> count(10, 0);  // 0~9 숫자별 사용 횟수 카운트

    for (char ch : num) {
        int digit = ch - '0';
        if (digit == 6 || digit == 9) {
            count[6]++;
        } else {
            count[digit]++;
        }
    }

    // 6과 9는 서로 대체 가능 → 2로 나누고 올림
    count[6] = (count[6] + 1) / 2;

    // 최댓값이 필요한 세트 수
    int ans = 0;
    for (int i = 0; i < 9; i++) {  // 0~8까지 (9는 6으로 처리됨)
        ans = max(ans, count[i]);
    }

    cout << ans << '\n';
    return 0;
}

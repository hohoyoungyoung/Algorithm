#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> odd_numbers;  // 홀수 저장용

    for (int i = 0; i < 7; ++i) {
        int num;
        cin >> num;

        if (num % 2 == 1) {
            odd_numbers.push_back(num);  // 벡터에 추가
        }
    }

    if (odd_numbers.empty()) {
        cout << -1 << endl;  // 홀수가 하나도 없으면 -1 출력
    } else {
        int sum = 0;
        int min_val = odd_numbers[0];

        for (int x : odd_numbers) {
            sum += x;
            if (x < min_val) min_val = x;
        }

        cout << sum << endl;
        cout << min_val << endl;
    }

    return 0;
}

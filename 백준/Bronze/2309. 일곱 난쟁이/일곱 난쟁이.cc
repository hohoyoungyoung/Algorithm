#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> height(9);
    int total = 0;
    for (int i = 0; i < 9; ++i) {
        cin >> height[i];
        total += height[i];
    }

    vector<int> ans;

    for (int i = 0; i < 8; ++i) {
        for (int j = i + 1; j < 9; ++j) {
            if (total - height[i] - height[j] == 100) {
                for (int k = 0; k < 9; ++k) {
                    if (k != i && k != j)
                        ans.push_back(height[k]);
                }
                // ✅ 여기서 break는 안 써도 괜찮음 (return 이전 정리만 잘 하면)
                goto DONE;  // 빠른 탈출 (C++에선 가독성 고려 시 종종 사용)
            }
        }
    }

DONE:
    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}

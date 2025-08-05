#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> lst(n);

    for (int i = 0; i < n; i++) {
        cin >> lst[i];
    }

    sort(lst.begin(), lst.end());

    int target;
    cin >> target;

    int i = 0;
    int j = n - 1;
    int ans = 0;

    while (i < j) {
        int sum = lst[i] + lst[j];

        if (sum == target) {
            ans++;
            i++;
            j--;  // 둘 다 이동 (같은 쌍 다시 안세기 위해)
        }
        else if (sum < target) {
            i++;
        }
        else {
            j--;
        }
    }

    cout << ans << '\n';
    return 0;
}

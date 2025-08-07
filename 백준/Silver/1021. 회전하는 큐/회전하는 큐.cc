#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N, M, target, ans = 0;
    cin >> N >> M;

    deque<int> dq;
    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }

    while (M--) {
        cin >> target;
        int idx = 0;

        for (int i = 0; i < dq.size(); i++) {
            if (dq[i] == target) {
                idx = i;
                break;
            }
        }

        if (idx <= dq.size() / 2) {
            while (idx--) {
                dq.push_back(dq.front());
                dq.pop_front();
                ans++;
            }
        } else {
            int n = dq.size() - idx;
            while (n--) {
                dq.push_front(dq.back());
                dq.pop_back();
                ans++;
            }
        }

        dq.pop_front();
    }

    cout << ans << '\n';
}

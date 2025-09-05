#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int,int>> meetings; // class → meetings

    while (N--) {
        int a, b;
        cin >> a >> b;
        meetings.push_back({a, b});
    }

    // 끝나는 시간이 짧은 순, 같으면 시작 시간 짧은 순
    sort(meetings.begin(), meetings.end(), [](pair<int,int> &p1, pair<int,int> &p2) {
        if (p1.second == p2.second) return p1.first < p2.first;
        return p1.second < p2.second;
    });

    int ans = 0;
    int end_time = 0;

    for (int i = 0; i < meetings.size(); i++) {
        if (meetings[i].first >= end_time) {
            end_time = meetings[i].second;
            ans++;
        }
    }

    cout << ans;
}

// 첫째 줄에 현재 휴게소의 개수 N, 더 지으려고 하는 휴게소의 개수 M, 고속도로의 길이 L이 주어진다. 
// 둘째 줄에 현재 휴게소의 위치가 공백을 사이에 두고 주어진다.
//  N = 0인 경우 둘째 줄은 빈 줄이다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

bool can(int D, const vector<int> gaps, int M) {
    long long need = 0;
    for (int g : gaps) {
        if (g > D) need += (g-1)/D;
        if (need > M) return false;
    }
    return need <= M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M,L;
    cin >> N >> M >> L;

    vector<int> pos(N);
    for (int i=0; i<N; i++) cin >> pos[i];

    pos.push_back(0);
    pos.push_back(L);
    sort(pos.begin(), pos.end());

    vector<int> gaps;
    for (int i=1; i<pos.size(); i++) {
        gaps.push_back(pos[i]-pos[i-1]);
    }

    int lo = 1, hi = L - 1, ans = L - 1;
    while (lo<=hi) {
        int mid = (lo + hi) / 2;
        if (can(mid, gaps, M)) {
            ans = mid;
            hi = mid - 1; //더 줄여보기
        } else {
            lo = mid + 1; //불가능 -> 키우기
        }
    }

    cout << ans << '\n';
    return 0;
}
#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    map<long long,int> freq; // 카드 번호 -> 빈도수

    for (int i=0; i<N; i++) {
        long long a;
        cin >> a;
        freq[a]++;   // 자동으로 카운트
    }

    long long ans = 0;
    int maxCnt = 0;

    for (auto &p : freq) {
        if (p.second > maxCnt) {
            maxCnt = p.second;
            ans = p.first;   // 빈도수 최댓값 갱신
        }
    }

    cout << ans << "\n";
}

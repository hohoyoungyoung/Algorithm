#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> rope(N, 0);
    int all_sum = 0;

    for (int i=0; i<N; i++) {
        cin >> rope[i];
        
    }

    sort(rope.begin(), rope.end());

    int ans = 0;
    int division = N;

    for (int i=0; i<N; i++) {
        ans = max(rope[i]*division, ans);
        division--;
    }

    cout << ans;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M;

int main() {
    cin >> T;

    while (T--) {
        int ans=0;
        cin >> N >> M;

        vector<int> vec1(N,0);
        vector<int> vec2(M,0);

        for (int i=0; i<N; i++) {
            cin >> vec1[i];
        }

        for (int i=0; i<M; i++) {
            cin >> vec2[i];
        }

        sort(vec1.begin(), vec1.end(), greater<int>());
        sort(vec2.begin(), vec2.end());

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (vec1[i] > vec2[j]) ans++;
                else {
                    break;
                } 
            }
        }

        cout << ans << '\n';
    }
}
// B를 보고 A를 맞춰야 하는데..
// B의 큰값에 A의 작은 값이 가야함
// 엥 근데 B를 못바꿔도 결국 같은 위치 곱이기 때문에 맘대로 해도 되네?
// 그냥 A 오름차순, B 내림차순해서 다 곱하기

#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N, 0);
    vector<int> B(N, 0);

    for (int i=0; i<N; i++) {
        cin >> A[i]; 
    }

    for (int i=0; i<N; i++) {
        cin >> B[i]; 
    }

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end());

    int ans = 0;

    for (int i=0; i<N; i++) {
        ans += (A[i] * B[i]);
    }

    cout << ans;
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> stairs(N);
    
    for (int i=0; i<N; i++) {
        cin >> stairs[i];
    }

    vector<int> dp(N);

    if (N==1) {
        cout << stairs[0];
    }
    else if (N==2) {
        cout <<stairs[0]+stairs[1];
    }
    else if (N==3) {
        cout << max(stairs[1]+stairs[2],stairs[0]+stairs[2]);
    }

    else {
    dp[0] = stairs[0];
    dp[1] = stairs[0] + stairs[1];
    dp[2] = max(stairs[1]+stairs[2], stairs[0]+stairs[2]);

    for (int i=3;i<N;i++) {
        dp[i] = max(dp[i-3]+stairs[i-1]+stairs[i], dp[i-2]+stairs[i]);
    }

    cout << dp[N-1];  
    }
return 0;
}
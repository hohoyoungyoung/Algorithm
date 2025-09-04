#include <iostream>
#include <vector>


using namespace std;

int main() {
    int T;

    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> dp(n+1, 0);
        
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;

        for (int i=4; i<n+1; i++) dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        
        cout << dp[n] << '\n';
    }
}
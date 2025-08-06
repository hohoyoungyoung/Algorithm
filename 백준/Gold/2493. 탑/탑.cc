#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    vector<int> vec;
    stack<int> st;

    cin >> N;

    vector<int> ans(N, 0); 

    while (N--) {
        cin >> K;
        vec.push_back(K);
    }

    for (int i = vec.size() - 1; i >= 0; i--) {
        if (i == vec.size() - 1) {
            st.push(i); 
            continue;
        }

        while (!st.empty() && vec[i] > vec[st.top()]) {
            ans[st.top()] = i + 1;  
            st.pop();
        }

        st.push(i); 
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}

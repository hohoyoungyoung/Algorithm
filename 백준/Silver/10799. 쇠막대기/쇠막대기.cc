#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string input;
    stack<char> st;
    int ans = 0;

    cin >> input;
    bool previous = false;

    for (char ch : input) {
        if (ch == '(') {
            st.push('(');
            previous = true;
        }
        else if (ch == ')') {
            if (previous == true) {
                st.pop();           // 레이저 괄호 '(' 제거
                ans += st.size();   // 현재 열려있는 막대기 수만큼 잘림
            }
            else {
                st.pop();           // 막대기 끝 괄호 제거
                ans += 1;           // 조각 하나 추가
            }
            previous = false;
        }
    }

    cout << ans << '\n';
    return 0;
}

#include <string>
using namespace std;

bool solution(string s) {
    int cnt = 0;
    for (char c : s) {
        if (c == '(') cnt++;
        else cnt--;

        if (cnt < 0) return false;  // 닫는 괄호가 먼저 나오면 실패
    }
    return cnt == 0;
}

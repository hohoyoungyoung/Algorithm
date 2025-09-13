#include <string>
#include <vector>
#include <climits>
using namespace std;

string solution(string s) {
    string sTemp = "";
    int minVal = INT_MAX, maxVal = INT_MIN;

    for (int i = 0; i <= s.size(); i++) {
        if (i == s.size() || s[i] == ' ') {
            int num = stoi(sTemp);
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
            sTemp.clear();
        } else {
            sTemp += s[i];
        }
    }

    return to_string(minVal) + " " + to_string(maxVal);
}

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int zero_count = 0;
int cnt = 0;

string trans(string t) {
    string new_string;
    for (char c : t) {
        if (c == '0') zero_count++;
        else new_string += '1';
    }
    return new_string;
}

string binary(int n) {
    string res;
    while (n > 0) {
        res.push_back((n % 2) + '0');
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

vector<int> solution(string s) {
    while (s != "1") {
        s = trans(s);
        s = binary(s.size());
        cnt++;
    }
    return {cnt, zero_count};
}

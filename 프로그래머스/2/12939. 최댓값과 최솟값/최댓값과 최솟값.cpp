#include <string>
#include <sstream>
#include <limits>
#include <algorithm>

using namespace std;

string solution(string s) {
    stringstream ss(s);
    int num;
    int minVal = numeric_limits<int>::max();
    int maxVal = numeric_limits<int>::min();

    while (ss >> num) {
        minVal = min(minVal, num);
        maxVal = max(maxVal, num);
    }

    return to_string(minVal) + " " + to_string(maxVal);
}

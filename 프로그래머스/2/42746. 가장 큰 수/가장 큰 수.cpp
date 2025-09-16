//3, 30 있으면 무조건 3먼저오는게 이득임 -> 사전순


#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 커스텀 정렬 함수 - string은 합치는거
bool cmp(string a, string b) {
    return a + b > b + a; 
}

string solution(vector<int> numbers) {
    vector<string> arr;
    for (int n : numbers) {
        arr.push_back(to_string(n));
    }

    // 정렬
    sort(arr.begin(), arr.end(), cmp);

    // 정답 문자열 만들기
    string answer = "";
    for (string s : arr) answer += s;

    // "0000" 같은 경우 → "0" 리턴
    if (answer[0] == '0') return "0";
    return answer;
}

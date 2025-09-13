// 공백다음 무조건 대문자
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool previous = false;
    
    for (int i=0; i<s.size(); i++) {
        if (i==0) {answer += toupper(s[i]); continue;}
        
        if (s[i] == ' ') {
            previous = true;
        }
        else {
            if (previous == true) {
                answer += toupper(s[i]);
                previous = false;
                continue;
            }
        }
        
        answer += tolower(s[i]);
        
    }
    return answer;
}
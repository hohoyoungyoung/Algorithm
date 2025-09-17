// 사실 중간에 A가 없으면 그냥 위로올리는거랑 옆으로만 가도됨. 문제는 이 예외를 어떻게..?
// A가 그냥 있으면 return + 1 <- 이거 아니라고 함. 왜냐하면 AAA가 이렇게 연속이면 그냥 안봐도되니까
// 알파벳 기준 절반아래면 올리고 절반위면 내린다.

#include <string>
#include <algorithm>
using namespace std;

int solution(string name) {
    int n = name.size();
    int answer = 0;
    
    // 1. 위/아래 조작 횟수
    for (char ch : name) {
        answer += min(ch - 'A', 'Z' - ch + 1);
    }
    
    // 2. 좌/우 이동 최소화
    int move = n - 1;
    for (int i = 0; i < n; i++) {
        int next_i = i + 1;
        while (next_i < n && name[next_i] == 'A') next_i++;
        
        move = min({
            move,
            i*2 + (n - next_i),
            i + 2*(n - next_i)
        });
    }
    
    answer += move;
    return answer;
}

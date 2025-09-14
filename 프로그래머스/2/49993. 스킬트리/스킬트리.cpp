
#include <string>
#include <vector>
#include <queue>
using namespace std;




int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (string tree : skill_trees) {
        queue<char> q;
        for (char c : skill) q.push(c);

        bool ok = true;
        for (char c : tree) {
            if (q.empty()) break; 

            // skill에 없는 스킬이면 무시
            bool isInSkill = false;
            for (char s : skill) if (s == c) { isInSkill = true; break; }
            if (!isInSkill) continue;

            if (c == q.front()) {
                q.pop(); 
            } else {
                ok = false; 
                break;
            }
        }
        if (ok) answer++;
    }
    return answer;
}

#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> check;

    // 참가자 수 카운트
    for (auto &p : participant) {
        check[p]++;
    }

    // 완주자 수 빼기
    for (auto &c : completion) {
        check[c]--;
    }

    // 아직 남아있는 사람 = 완주 못한 사람
    for (auto &p : participant) {
        if (check[p] > 0) {
            return p;
        }
    }

    return "";
}

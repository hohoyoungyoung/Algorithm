#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(string word) {
    vector<int> weight = {781, 156, 31, 6, 1};
    string vowels = "AEIOU";
    unordered_map<char, int> idx;
    for (int i = 0; i < vowels.size(); i++) idx[vowels[i]] = i;
    
    int answer = 0;
    for (int i = 0; i < word.size(); i++) {
        answer += idx[word[i]] * weight[i];
        answer += 1; // 자기 자리 포함
    }
    return answer;
}

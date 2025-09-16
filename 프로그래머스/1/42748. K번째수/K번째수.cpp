#include <string>
#include <vector>
#include <algorithm>  // sort 사용하려면 필요
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (auto command : commands) {
        int start = command[0];
        int end = command[1];
        int pos = command[2];
        
        // 부분 배열 슬라이싱 (start-1 ~ end-1)
        vector<int> temp(array.begin() + start - 1, array.begin() + end);

        sort(temp.begin(), temp.end());

        // pos번째 수 (1-indexed라서 pos-1)
        answer.push_back(temp[pos - 1]);
    }
    
    return answer;
}

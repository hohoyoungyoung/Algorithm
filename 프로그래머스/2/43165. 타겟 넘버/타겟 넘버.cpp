#include <bits/stdc++.h>
using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int idx, int sum) {
    if (idx == numbers.size()) {
        if (sum == target) answer++;
        return;
    }
    // 현재 숫자 더하기
    dfs(numbers, target, idx+1, sum + numbers[idx]);
    // 현재 숫자 빼기
    dfs(numbers, target, idx+1, sum - numbers[idx]);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return answer;
}

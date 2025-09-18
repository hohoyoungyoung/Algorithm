// 6*10 = 60 까지 가는데, 30으로 충분해? 아니면 45 충분해? 아니면 37.5 약간이런느낌.
// 충분한지는   30/7 30/10 -> 4 + 3 >= n 
// 28/7 = 4   28/10 = 2 -> 6명커버

#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = LLONG_MAX;
    sort(times.begin(), times.end()); // 안해도 되지만 back()을 위해 ㅎㅎ.ㅎ
    
    long long left = 1;                         // 최소 1분
    long long right = (long long)times.back() * n; // 최악의 경우 (가장 느린 심사관이 다 처리)
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        
        // mid 분 동안 처리 가능한 사람 수 계산
        long long people = 0;
        for (int t : times) {
            people += mid / t;
            if (people >= n) break; // 이미 n명 이상이면 더 안세도 됨
        }
        
        if (people >= n) {
            // 충분히 처리 가능 → 더 작은 시간도 가능할지 탐색
            answer = mid;
            right = mid - 1;
        } else {
            // 부족 → 시간을 더 늘려야 함
            left = mid + 1;
        }
    }
    return answer;
}

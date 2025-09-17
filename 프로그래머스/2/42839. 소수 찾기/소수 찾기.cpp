// // 내 의문.... numbers가 길어지면 어떻게 모든 경우의 수를 보는가?
// // -> 다 보는게 맞았네;;; dfs 나 permutaion

// #include <string>
// #include <vector>
// #include <set>
// #include <algorithm>
// #include <cmath>
// using namespace std;

// // 소수 판별 함수
// bool isPrime(int n) {
//     if (n < 2) return false;
//     for (int i = 2; i <= sqrt(n); i++) {
//         if (n % i == 0) return false;
//     }
//     return true;
// }

// int solution(string numbers) {
//     set<int> candidates;
//     sort(numbers.begin(), numbers.end());
    
//     // 길이 1 ~ n 까지 조합 생성
//     do {
//         for (int len = 1; len <= numbers.size(); len++) {
//             int num = stoi(numbers.substr(0, len));
//             candidates.insert(num);
//         }
//     } while (next_permutation(numbers.begin(), numbers.end()));
    
//     // 소수 개수 세기
//     int count = 0;
//     for (int num : candidates) {
//         if (isPrime(num)) count++;
//     }
//     return count;
// }


// #include <string>
// #include <vector>
// #include <set>
// #include <cmath>
// using namespace std;

// // 소수 판별 함수
// bool isPrime(int n) {
//     if (n < 2) return false;
//     for (int i = 2; i <= sqrt(n); i++) {
//         if (n % i == 0) return false;
//     }
//     return true;
// }

// set<int> candidates;
// vector<bool> visited;

// void dfs(string numbers, string current) {
//     if (!current.empty()) {
//         candidates.insert(stoi(current)); // 숫자 집합에 추가
//     }
//     for (int i = 0; i < numbers.size(); i++) {
//         if (!visited[i]) {
//             visited[i] = true;
//             dfs(numbers, current + numbers[i]);
//             visited[i] = false;
//         }
//     }
// }

// int solution(string numbers) {
//     visited.assign(numbers.size(), false);
//     dfs(numbers, "");
    
//     int count = 0;
//     for (int num : candidates) {
//         if (isPrime(num)) count++;
//     }
//     return count;
// }




#include <string>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    set<int> candidates;
    queue<pair<string, vector<bool>>> q;
    vector<bool> visited(numbers.size(), false);
    
    q.push({"", visited});
    
    while (!q.empty()) {
        auto [current, used] = q.front();
        q.pop();
        
        if (!current.empty()) {
            candidates.insert(stoi(current));
        }
        
        for (int i = 0; i < numbers.size(); i++) {
            if (!used[i]) {
                auto next_used = used;
                next_used[i] = true;
                q.push({current + numbers[i], next_used});
            }
        }
    }
    
    int count = 0;
    for (int num : candidates) {
        if (isPrime(num)) count++;
    }
    return count;
}

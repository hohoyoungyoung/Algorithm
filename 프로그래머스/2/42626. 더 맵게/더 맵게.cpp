// 최소 힙에서 2개씩 빼고 그 두게 합쳐서 넣고 다시 2개빼고 반복... 처음 빼는게 k>=이면 종료

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    
    int answer = -1;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    
    if (scoville.size() < 2) {
        if (scoville[0] >= K) return 0;
        else {return -1;}
    }
    for (int i=0; i<scoville.size(); i++) {
        min_heap.push(scoville[i]);
    }
    
    
    while (true) {
        if (min_heap.size() == 1) {
            if (min_heap.top() >= K) return answer+1;
            else {return -1;}
        }
        answer++;
        int a = min_heap.top();
        min_heap.pop();
        int b = min_heap.top();
        min_heap.pop();
        int scovilles = a + (b*2);
    
        if (a >= K) return answer;
        
        min_heap.push(scovilles);
    }
    
    return answer;
}
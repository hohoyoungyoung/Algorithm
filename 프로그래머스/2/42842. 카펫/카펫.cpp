#include <string>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
    int total = brown + yellow;
    
    for (int h = 3; h <= total; h++) {
        if (total % h != 0) continue;
        int w = total / h;
        
        if (w < h) continue;  // 가로 >= 세로 조건
        
        if ((w - 2) * (h - 2) == yellow) {
            return {w, h};
        }
    }
    return {};
}

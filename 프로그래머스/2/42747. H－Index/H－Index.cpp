
// 0,1,3,5,6
// 6,5,3,1,0    
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    int h = 0;
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] >= i+1) {
            h = i+1;
        }
    }
    return h;
}

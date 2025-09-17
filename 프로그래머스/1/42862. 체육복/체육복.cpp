// 최대한 많은 학생이 체육복.
// 체육복 보유 개수를 list로 만들고, lost는 0이겠지? 그리고 lost의 왼쪽 여분 있으면 받고 없으면 오른쪽, 이렇게 해서 0초과 개수 세기?


#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    // 교집합 처리
    vector<int> realLost, realReserve;
    for (int l : lost) {
        if (find(reserve.begin(), reserve.end(), l) != reserve.end()) {
            reserve.erase(find(reserve.begin(), reserve.end(), l));
        } else {
            realLost.push_back(l);
        }
    }
    realReserve = reserve;

    sort(realLost.begin(), realLost.end());
    sort(realReserve.begin(), realReserve.end());

    for (int l : realLost) {
        auto it = find(realReserve.begin(), realReserve.end(), l-1);
        if (it != realReserve.end()) {
            realReserve.erase(it);
        } else {
            it = find(realReserve.begin(), realReserve.end(), l+1);
            if (it != realReserve.end()) {
                realReserve.erase(it);
            } else {
                n--; // 빌릴 수 없으면 수업 못 들음
            }
        }
    }
    return n;
}

// 원래의 가로 최대, 원래의 세로 최대
// 가로 > 세로 -> 세로를 가로로 넣기
// 가_최 = 7  세_최 = 19 
#include <string>
#include <vector>

using namespace std;


int solution(vector<vector<int>> sizes) {
    int garo = 0;
    int sero = 0;
    int garo_max = 0;
    int sero_max = 0;
    for (auto size: sizes) {
        garo = size[0];
        sero = size[1];
        
        if (size[0] > size[1]) {
            sero = size[0];
            garo = size[1];}
    
        garo_max = max(garo_max, garo);
        sero_max = max(sero_max, sero);
    }
    
    return garo_max * sero_max;
}
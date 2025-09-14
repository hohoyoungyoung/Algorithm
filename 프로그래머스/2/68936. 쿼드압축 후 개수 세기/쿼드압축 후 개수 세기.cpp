// 2의 N승 2의 N-1승 이렇게 작아짐. 정사각형 한변의 길이
// 모든게 0인지 or 1인지 판별해주는 함수
// (0,0) -> (0,0) (0+2,0) (0, 0+2) (0+2, 0+2) - 2의 1승이니까 2*2사이즈 확인
//   (0,0) (0,0+2의 0승) (0+2의 0승,0) (0+2의 0승,0+2의 0승) - 2의 0승이니까 1*1 사이즈 확인


#include <iostream>
#include <vector>
#include <queue>
#include <tuple>  // 추가

using namespace std;

vector<int> solution(vector<vector<int>> arr) {
    int n = arr.size();
    vector<int> answer(2, 0);  // [0 개수, 1 개수]

    queue<tuple<int,int,int>> q;
    q.push({0, 0, n});  // (x, y, size)

    while (!q.empty()) {
        auto [x, y, size] = q.front();
        q.pop();

        int first = arr[x][y];
        bool same = true;

        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                if (arr[i][j] != first) {
                    same = false;
                    break;
                }
            }
            if (!same) break;
        }

        if (same) {
            answer[first]++;
        } else {
            int half = size / 2;
            q.push({x, y, half});
            q.push({x, y + half, half});
            q.push({x + half, y, half});
            q.push({x + half, y + half, half});
        }
    }

    return answer;
}


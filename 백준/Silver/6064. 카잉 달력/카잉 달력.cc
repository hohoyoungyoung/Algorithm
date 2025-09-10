#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric> 
#include <cmath>
using namespace std;

// 작은게 몇번 도는지 고르고 거기서 나머지로 맞추기

int main() {
    int T;
    cin >> T;

    while (T--) {
        int M, N, x, y, max_num2, min_num2;
        cin >> M >> N >> x >> y;

        int max_num = max(M, N);
        int min_num = min(M, N);

        if (max_num == M) {
            max_num2 = x;
            min_num2 = y;
        }
        else {
            max_num2 = y;
            min_num2 = x;
        }

        bool test = false;

    for (int i=0; i<lcm(M,N)/min_num; i++) {
        int val = min_num2 + min_num * i;
        int mod = val % max_num == 0 ? max_num : val % max_num;
        if (mod == max_num2) {
            cout << val << '\n';
            test = true;
            break;
        }
    }


        if (test == false) cout << -1 <<'\n';

        //(3,3+10*0) (3, (3+10*1)%12)  (3, (3+10*2)%12)    (3, (3+10*3)%12)
        //3               13              23                 33            
        // 5, 5+11*0     5, (5+11*1)%13     5, 5+11*2  5, 5+11*3    5,5+11*6
    }
}

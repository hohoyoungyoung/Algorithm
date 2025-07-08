#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

// 영식 - 30초마다 10원씩
// 민식 - 60초마다 15원씩 즉, 60 보다 작을때 15 , 60되면 30원 되는거임.

// 영식: (입력되는 시간 //30 + 1) * 10
// 민식: (입력되는 시간 //60 + 1) * 15


int main() {
    int N;
    int num;
    int Y = 0, M = 0;

    string line;

    cin >> N;
    cin.ignore(); // \n제거

    getline(cin, line);
    stringstream ss(line);

    while (ss >> num) {
        Y += (num / 30 + 1) * 10;
        M += (num / 60 + 1) * 15;
    }

    if (Y<M) {
        cout << "Y " << Y;
    }
    else if (Y>M) {
        cout << "M " << M; 
    }
    else {
        cout << "Y M " << Y;
    }
}

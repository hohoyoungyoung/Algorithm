#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    int sex, grade;

    cin >> N >> K;

    vector<int> man(7, 0);    // 1~6학년
    vector<int> woman(7, 0);

    for (int i = 0; i < N; i++) {
        cin >> sex >> grade;
        if (sex == 0) {
            woman[grade]++;
        } else {
            man[grade]++;
        }
    }

    int room_count = 0;

    for (int j = 1; j <= 6; j++) {
        room_count += (man[j] + K - 1) / K;
        room_count += (woman[j] + K - 1) / K;
    }

    cout << room_count << '\n';
    return 0;
}

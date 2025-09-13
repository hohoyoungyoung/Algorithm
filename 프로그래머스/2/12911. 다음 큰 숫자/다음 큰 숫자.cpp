#include <string>
#include <vector>
using namespace std;

string binary(int n) {
    if (n == 1) return "1";
    string bin_string = "";
    while (n > 0) {
        // 앞에 붙여서 올바른 순서로 저장
        bin_string = to_string(n % 2) + bin_string;
        n = n / 2;
    }
    return bin_string;
}

int one_check(string num) {
    int one_count = 0;
    for (char i : num) {
        if (i == '1') one_count++;
    }
    return one_count;
}

int solution(int n) {
    int target = one_check(binary(n));
    for (int i = n + 1;; i++) {
        if (one_check(binary(i)) == target) return i;
    }
}

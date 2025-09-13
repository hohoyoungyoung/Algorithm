// 무조건 다음수는 커져야함
// 
#include <string>
#include <vector>

using namespace std;

string binary(int n) {
    if (n==1) return "1";
    string bin_string = "";
    while (n>0) {
        bin_string = bin_string + to_string(n % 2);
        n = n / 2;
    }
    
    return bin_string;
}

int one_check(string num) {
    int one_count = 0;
    
    for (char i: num) {
    if (i=='1') one_count++;    
    }
    
    return one_count;
}


int solution(int n) {
    int i = n;
    int target = one_check(binary(n));
    
    while (true) {
        i++;
        if (one_check(binary(i)) == target) break;        
    }
    
    return i;
}
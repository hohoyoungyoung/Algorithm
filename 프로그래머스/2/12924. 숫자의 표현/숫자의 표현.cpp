#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int count = 0;
    int left = 1, right = 1, sum = 1;

    while (left <= n) {
        if (sum == n) {
            count++;
            sum -= left;
            left++;
        } else if (sum < n) {
            right++;
            sum += right;
        } else { // sum > n
            sum -= left;
            left++;
        }
    }
    return count;
}

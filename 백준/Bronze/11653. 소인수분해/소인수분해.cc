#include <iostream>

using namespace std;

int main() {
    int i = 2;

    int N;
    cin >> N;

    while (i<= N) {
        
        if (N % i != 0) {
            i++;
        }
        
        else {
            N = N/i;
            cout << i << '\n';
        }
    }
}
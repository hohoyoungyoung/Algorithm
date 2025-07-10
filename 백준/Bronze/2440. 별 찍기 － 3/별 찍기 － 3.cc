#include <iostream>
#include <string>
using namespace std;


int main() {
    int N;
    cin >> N;

    while (N) {
        string result(N, '*');
        cout << result << '\n';
        N--;
    }
}
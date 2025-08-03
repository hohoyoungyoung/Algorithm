#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int space = 0;
    int k = 0;
    for (int i = 0; i<n; i++) {
        cout << string(space, ' ');
        cout << string(2*n-1-k, '*');

        cout << '\n';

        space += 1;
        k += 2;
        
    }
}

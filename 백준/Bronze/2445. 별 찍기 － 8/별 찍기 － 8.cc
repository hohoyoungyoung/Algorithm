#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int space = 2*n-2;
    int k = 1;
    for (int i = 0; i<n-1; i++) {
        cout << string(k, '*');
        cout << string(space, ' ');
        cout << string(k, '*');
        cout << '\n';

        space -= 2;
        k += 1;
        
    }

    //cout << string(2*n, '*') << '\n';


    for (int i = 0; i<n; i++) {
        cout << string(k, '*');
        cout << string(space, ' ');
        cout << string(k, '*');
        cout << '\n';

        space += 2;
        k -= 1;
    }

}

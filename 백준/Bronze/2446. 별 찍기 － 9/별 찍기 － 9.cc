#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int star = 2*n-1;
    int space = 0;


    for (int i=0; i<n-1; i++) {
        cout << string(space, ' ') << string(star,'*') << '\n';

        space += 1;
        star -=2;

    } 


    for (int i=0; i<n; i++) {
        cout << string(space, ' ') << string(star,'*');
        if (i!= n-1) cout << '\n';
        space -= 1;
        star += 2;
    }

}



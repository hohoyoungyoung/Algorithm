#include <iostream>
#include <string>

using namespace std;

string repeat(string s, int n) {
    string result = "";
    for (int i = 0; i < n; i++) {
        result += s;
    }
    return result;
}


int main() {
    int n;
    cin >> n;

    for (int i=n; i>0; i--) {
        cout << repeat(" ", n-i)  << repeat("*", i) <<'\n';
    }
}
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    string sen;
    list<char> L;

    cin >> sen;

    for (char c : sen) {
        L.push_back(c);
    }

    int N;
    cin >> N;

    list<char>::iterator cursor = L.end();  // 커서는 문자열 끝에서 시작

    while (N--) {
        string command;
        cin >> command;

        if (command == "P") {
            char x;
            cin >> x;
            L.insert(cursor, x);
        }
        else if (command == "L") {
            if (cursor != L.begin()) cursor--;
        }
        else if (command == "D") {
            if (cursor != L.end()) cursor++;
        }
        else if (command == "B") {
            if (cursor != L.begin()) {
                cursor--;
                cursor = L.erase(cursor);  // erase 후 반환되는 위치로 갱신
            }
        }
    }

    for (char c : L) {
        cout << c;
    }

    return 0;
}

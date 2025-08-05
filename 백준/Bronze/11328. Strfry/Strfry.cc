#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int t = 0; t < N; t++) {
        string a, b;
        cin >> a >> b;

        if (a.size() != b.size()) {
            cout << "Impossible\n";
            continue;
        }

        vector<int> alpha(26, 0);

        for (char ch : a) {
            alpha[ch - 'a']++;
        }

        for (char ch : b) {
            alpha[ch - 'a']--;
        }

        bool is_possible = true;
        for (int cnt : alpha) {
            if (cnt != 0) {
                is_possible = false;
                break;
            }
        }

        cout << (is_possible ? "Possible" : "Impossible") << '\n';
    }

    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// 길이가 짧은게 앞에
// 숫자 다더해서 작은거 앞에
// 사전순


int num_check(string s) {
    int sum = 0;

    for (int i=0; i<s.size(); i++) {
        if (isdigit(s[i])) {
            sum += s[i]-'0';
        }
    }
    return sum;
}


bool cmp(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    if (num_check(a) != num_check(b)) return num_check(a) < num_check(b);
    return a < b;
}



int main() {
    int N;
    cin >> N;
    vector<string> box(N);

    for (int i=0; i<N; i++) {
        cin >> box[i];
    }

    sort(box.begin(), box.end(), cmp);


    for (int i=0; i<box.size(); i++) {
        cout << box[i] << '\n';
    }
}
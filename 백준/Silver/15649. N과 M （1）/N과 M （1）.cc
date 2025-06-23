#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> seq;
vector<bool> visited;

void backtrack() {
    if (seq.size() == M) {
        for (int num : seq) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            seq.push_back(i);

            backtrack();

            seq.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;

    visited.resize(N + 1, false);

    backtrack();

    return 0;
}

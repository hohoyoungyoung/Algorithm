#include <iostream>
#include <deque>
#include <vector>

using namespace std;

const int MAX = 100001;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> distance(MAX, -1);
    distance[N] = 0;

    deque<int> dq;
    dq.push_back(N);

    while (!dq.empty()) {
        int pos = dq.front();
        dq.pop_front();

        vector<pair<int, int>> moves = {
            {pos * 2, 0},
            {pos - 1, 1},
            {pos + 1, 1}
        };

        for (auto& move : moves) {
            int next_pos = move.first;
            int cost = move.second;

            if (0 <= next_pos && next_pos < MAX) {
                if (distance[next_pos] == -1 || distance[next_pos] > distance[pos] + cost) {
                    distance[next_pos] = distance[pos] + cost;
                    if (cost == 0)
                        dq.push_front(next_pos);
                    else
                        dq.push_back(next_pos);
                }
            }
        }
    }

    cout << distance[K] << '\n';
    return 0;
}

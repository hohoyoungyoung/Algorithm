// 이거 그냥 소모 피로도가 작은거부터 먹으면 되는거 같음.
// 단 조건은 최소 필요 피로도 보다 커야겠지?
// DUNGEONS 두번째 기준으로 오름차순 배열
// 어아니네 K랑 가장 근접한 최소 필요 피로도 부터하기? 어 이거도 아니네
// NEXT_PERMUTATIONS으로 순서 다보기 해서 RESULT 가장큰거

#include <bits/stdc++.h>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int n = dungeons.size();
    vector<int> order(n);
    for (int i = 0; i < n; i++) order[i] = i;

    int answer = 0;
    do {
        int fatigue = k;
        int cnt = 0;
        for (int idx : order) {
            int need = dungeons[idx][0];
            int cost = dungeons[idx][1];
            if (fatigue >= need) {
                fatigue -= cost;
                cnt++;
            } else break; // 더 못 들어가면 멈춤
        }
        answer = max(answer, cnt);
    } while (next_permutation(order.begin(), order.end()));

    return answer;
}

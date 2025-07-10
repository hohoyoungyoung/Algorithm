#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void swap(int idx1, int idx2, vector<int>& card) {
    int temp;
    temp = card[idx1];
    card[idx1] = card[idx2];
    card[idx2] = temp;
}


int main() {
    vector <int> card(21);

    for (int i=1; i<21;i++) {
        card[i] = i; 
    }

    int k;
    k = 10;

    while (k) {
        int idx1, idx2;
        cin >> idx1 >> idx2;

        for (int i=0; i<(idx2-idx1+1)/2; i++) {
            swap(idx1+i, idx2-i, card);
        }

        k--;
    }

    for (int i = 1; i <= 20; i++) {
        cout << card[i] << ' ';
    }




}
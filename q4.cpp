#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    unordered_map<string, int> countMap;
    for (int i = 0; i < N; i++) {
        countMap[C[i]]++;
    }

    bool found = false;
    for (int i = 0; i < N; i++) {
        if (countMap[C[i]] % 2 != 0) {
            cout << C[i] << endl;
            countMap[C[i]] = -1;
            found = true;
        }
    }

    if (!found) {
        cout << "All are even" << endl;
    }

    return 0;
}

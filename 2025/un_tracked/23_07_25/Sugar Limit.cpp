#include <bits/stdc++.h>
using namespace std;

int maxSatisfaction(int N, vector<int>& T, vector<int>& S) {
    int maxSat = 0;

    for (int L = 0; L <= 100; L++) {
        int totalTastiness = 0;
        for (int i = 0; i < N; i++) {
            if (S[i] <= L && T[i] > 0) {
                totalTastiness += T[i];
            }
        }
        maxSat = max(maxSat, totalTastiness - L);
    }

    return maxSat;
}


int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> T(N);
        vector<int> S(N);
        for (int i = 0; i < N; i++) {
            cin >> T[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> S[i];
        }

        cout << maxSatisfaction(N, T, S) << endl;
    }

    return 0;
}

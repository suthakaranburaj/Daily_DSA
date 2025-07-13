#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        int maxProfit = 0;

        for (int X = 0; X <= 100; X++) {
            int revenue = 0, cost = X * 30 * N;

            for (int i = 0; i < N; i++) {
                revenue += min(X, A[i]) * 50;
            }

            int profit = revenue - cost;
            maxProfit = max(maxProfit, profit);
        }

        cout << maxProfit << endl;
    }

    return 0;
}

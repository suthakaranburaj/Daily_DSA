#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<long long> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        vector<long long> prefixMin(N);
        prefixMin[0] = A[0];
        for (int i = 1; i < N; ++i) {
            prefixMin[i] = min(prefixMin[i - 1], A[i]);
        }

        vector<long long> suffixMin(N);
        suffixMin[N - 1] = A[N - 1];
        for (int i = N - 2; i >= 0; --i) {
            suffixMin[i] = min(suffixMin[i + 1], A[i]);
        }

        long long minCost = LLONG_MAX;

        for (int i = 0; i < N - 1; ++i) {
            long long cost = prefixMin[i] + suffixMin[i + 1];
            minCost = min(minCost, cost);
        }

        minCost = min(minCost, A[0]);   
        minCost = min(minCost, A[N - 1]); 

        cout << minCost << "\n";
    }

    return 0;
}

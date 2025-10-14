#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minExtraCookies(int N, int C, vector<int>& A) {
    int extra = 0;
    while (true) {
        int newCookies = C + extra;
        bool hasSmaller = false;
        bool hasEqual = false;

        for (int i = 0; i < N; i++) {
            if (A[i] == newCookies) hasEqual = true;
            if (A[i] < newCookies) hasSmaller = true;
        }

        if (!hasEqual && hasSmaller) {
            return extra;
        }
        extra++;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, C;
        cin >> N >> C;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        cout << minExtraCookies(N, C, A) << endl;
    }

    return 0;
}

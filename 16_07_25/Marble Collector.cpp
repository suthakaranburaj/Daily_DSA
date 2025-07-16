#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        unordered_set<int> collected;

        for (int i = 0; i < N; i++) {
            int marble;
            cin >> marble;
            collected.insert(marble);
        }

        int not_collected = M - collected.size();
        cout << not_collected << endl;
    }

    return 0;
}

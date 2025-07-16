#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        vector<long long> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        
        sort(A.rbegin(), A.rend());
        
        vector<long long> base(N+1, 0);
        for (int t = 1; t <= N; t++) {
            base[t] = base[t-1] + A[t-1];
        }
        
        vector<long long> ans(2*N+1, LLONG_MIN);
        
        for (int j = 1; j <= 2*N; j++) {
            int low_t = (j + 1) / 2;
            int high_t = min(j, N);
            
            if (low_t > high_t) {
                ans[j] = LLONG_MIN;
                continue;
            }
            
            int left = low_t, right = high_t;
            
            while (right - left > 2) {
                int mid1 = left + (right - left) / 3;
                int mid2 = right - (right - left) / 3;
                
                int k1 = j - mid1;
                long long val1 = base[mid1] + (long long)k1 * (2LL * mid1 - k1 - 1) / 2;
                
                int k2 = j - mid2;
                long long val2 = base[mid2] + (long long)k2 * (2LL * mid2 - k2 - 1) / 2;
                
                if (val1 < val2) {
                    left = mid1;
                } else {
                    right = mid2;
                }
            }
            
            for (int t = left; t <= right; t++) {
                int k = j - t;
                long long total = base[t] + (long long)k * (2LL * t - k - 1) / 2;
                ans[j] = max(ans[j], total);
            }
        }
        
        for (int j = 1; j <= 2*N; j++) {
            cout << ans[j];
            if (j < 2*N) {
                cout << ' ';
            }
        }
        cout << '\n';
    }
    
    return 0;
}
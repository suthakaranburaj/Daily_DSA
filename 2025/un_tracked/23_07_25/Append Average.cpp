#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll N, K;
        cin >> N >> K;
        
        vector<ll> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        
        sort(A.begin(), A.end());
        
        // Find the two minimum elements
        ll min1 = A[0];
        ll min2 = A[1];
        
        // Calculate their average
        ll avg;
        if ((min1 + min2) % 2 == 0) {
            avg = (min1 + min2) / 2;
        } else {
            avg = (min1 + min2 + 1) / 2;
        }
        
        // Calculate sum of all original elements
        ll sum = 0;
        for (ll x : A) {
            sum += x;
        }
        
        // Key insight: We'll always be choosing min1 and min2 (or avg if it becomes smaller)
        // But since avg = ceil((min1 + min2)/2), and min1 <= min2, we have min1 <= avg <= min2
        // So we'll always choose min1 and avg in subsequent operations
        
        // After first operation: min1, avg
        // After second operation: min1, ceil((min1 + avg)/2)
        // And so on...
        
        // But there's a pattern: if min1 == min2, then avg == min1 == min2
        // In this case, all future operations will just add min1 to the array
        
        if (min1 == min2) {
            // All K operations will add min1 to the sum
            ll final_sum = sum + K * min1;
            cout << final_sum << endl;
        } else {
            // We need to simulate until we reach a stable state
            ll current_min1 = min1;
            ll current_min2 = min2;
            ll operations_done = 0;
            ll total_sum = sum;
            
            while (operations_done < K) {
                ll new_avg;
                if ((current_min1 + current_min2) % 2 == 0) {
                    new_avg = (current_min1 + current_min2) / 2;
                } else {
                    new_avg = (current_min1 + current_min2 + 1) / 2;
                }
                
                total_sum += new_avg;
                operations_done++;
                
                // Update the two minimums
                if (new_avg < current_min2) {
                    current_min2 = new_avg;
                } else {
                    // new_avg >= current_min2, so we'll keep choosing current_min1 and current_min2
                    // All remaining operations will add the same average
                    ll remaining_ops = K - operations_done;
                    total_sum += remaining_ops * new_avg;
                    break;
                }
                
                // If current_min1 == current_min2, all future operations will add current_min1
                if (current_min1 == current_min2) {
                    ll remaining_ops = K - operations_done;
                    total_sum += remaining_ops * current_min1;
                    break;
                }
            }
            
            cout << total_sum << endl;
        }
    }
    return 0;
}
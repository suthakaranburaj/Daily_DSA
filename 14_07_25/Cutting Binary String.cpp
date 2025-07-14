class Solution {
  public:

bool isPowerOfFive(long long num) {
    if (num == 0) return false;
    while (num % 5 == 0) {
        num /= 5;
    }
    return num == 1;
}

    int cuts(string s) {
        // code here
    int n = s.size();
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            // Skip if substring has leading zero
            if (s[j] == '0') continue;

            string sub = s.substr(j, i - j);
            long long num = stoll(sub, nullptr, 2);

            if (isPowerOfFive(num)) {
                if (dp[j] != INT_MAX)
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    return dp[n] == INT_MAX ? -1 : dp[n];
    }
};
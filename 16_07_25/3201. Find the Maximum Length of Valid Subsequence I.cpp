class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        int maxAlt = 1;
        int last = nums[0] % 2;
        for (int i = 1; i < n; ++i) {
            if ((nums[i] % 2) != last) {
                maxAlt++;
                last = nums[i] % 2;
            }
        }
        int even = 0, odd = 0;
        for (int x : nums) {
            if (x % 2 == 0) even++;
            else odd++;
        }

        return max({maxAlt, even, odd});
    }
};
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);
        for (int x : nums) {
            vector<long long> n(k, 0);
            int val = x % k;
            n[val]++;
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int nr = (r * val) % k;
                    n[nr] += dp[r];
                }
            }
            for (int r = 0; r < k; r++) {
                ans[r] += n[r];
            }
            dp = n;
        }
        return ans;
    }
};
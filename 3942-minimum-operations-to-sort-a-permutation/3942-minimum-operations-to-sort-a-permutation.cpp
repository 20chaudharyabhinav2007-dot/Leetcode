class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        bool forward = true, backward = true;
        int q = nums[0];
        for (int i = 0; i < n; i++) {
            if (nums[i] != (i + q) % n)
                forward = false;
            if (nums[i] != (q - i + n) % n)
                backward = false;
        }
        int ans = INT_MAX;
        if (forward) {
            if (q == 0) return 0;
            ans = min(n - q, q + 2);
        }
        if (backward) {
            int k = (n - 1 - q + n) % n;
            ans = min(ans, 1 + min(k, n - k));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
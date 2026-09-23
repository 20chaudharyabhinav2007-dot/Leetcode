class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), l = 0, ans = -1;
        long long sum = 0, total = 0;
        for (int a : nums) {
            total += a;
        }
        long long target = total - x;
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            while (sum > target && l <= r)
                sum -= nums[l++];
            if (sum == target)
                ans = max(ans, r - l + 1);
        }
        return ans == -1 ? -1 : n - ans;
    }
};
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> s(n);
        s[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            s[i] = min(nums[i], s[i + 1]);
        }
        int a = nums[0];
        for (int i = 0; i < n; i++) {
            a = max(a, nums[i]);
            if (a - s[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};
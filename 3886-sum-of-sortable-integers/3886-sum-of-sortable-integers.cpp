class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefDrop(n, 0);

        for (int i = 1; i < n; i++) {
            prefDrop[i] = prefDrop[i - 1] + (nums[i - 1] > nums[i]);
        }

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;
            int prevMax = INT_MIN;

            for (int start = 0; start < n; start += k) {
                int end = start + k - 1;
                int drops = prefDrop[end] - prefDrop[start];

                if (nums[end] > nums[start]) drops++;

                if (drops > 1) {
                    valid = false;
                    break;
                }

                int mn = INT_MAX, mx = INT_MIN;

                for (int i = start; i <= end; i++) {
                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);
                }

                if (prevMax > mn) {
                    valid = false;
                    break;
                }

                prevMax = mx;
            }

            if (valid) ans += k;
        }

        return ans;
    }
};
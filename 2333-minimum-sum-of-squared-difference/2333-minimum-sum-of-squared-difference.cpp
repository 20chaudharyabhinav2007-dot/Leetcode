
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diff;
        long long k = 1LL * k1 + k2;
        long long sum = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            diff.push_back(d);
            sum += d;
        }

        if (sum <= k) return 0;

        int low = 0, high = 100000;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long need = 0;

            for (int d : diff) {
                if (d > mid) need += d - mid;
            }

            if (need <= k)
                high = mid;
            else
                low = mid + 1;
        }

        long long ans = 0, used = 0;

        for (int d : diff) {
            int x = min(d, low);
            ans += 1LL * x * x;

            if (d > low) used += d - low;
        }

        long long rem = k - used;
        ans -= rem * (2LL * low - 1);

        return ans;
    }
};

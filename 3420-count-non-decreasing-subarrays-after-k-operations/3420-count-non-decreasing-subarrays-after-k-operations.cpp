class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int LOG = 20;

        vector<int> ng(n, n), st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.back()] <= nums[i]) {
                st.pop_back();
            }

            if (!st.empty()) {
                ng[i] = st.back();
            }

            st.push_back(i);
        }

        vector<vector<int>> up(LOG, vector<int>(n, n));
        vector<vector<long long>> sum(LOG, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            up[0][i] = ng[i];
            sum[0][i] = 1LL * nums[i] * (ng[i] - i);
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                int mid = up[j - 1][i];

                if (mid != n) {
                    up[j][i] = up[j - 1][mid];
                    sum[j][i] = sum[j - 1][i] + sum[j - 1][mid];
                } else {
                    sum[j][i] = sum[j - 1][i];
                }
            }
        }

        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        auto getCost = [&](int l, int r) -> long long {
            long long total = 0;
            int cur = l;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][cur] <= r) {
                    total += sum[j][cur];
                    cur = up[j][cur];
                }
            }

            total += 1LL * nums[cur] * (r - cur + 1);

            return total - (pref[r + 1] - pref[l]);
        };

        long long ans = 0;

        for (int r = 0; r < n; r++) {
            int low = 0;
            int high = r;
            int left = r + 1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (getCost(mid, r) <= k) {
                    left = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            ans += r - left + 1;
        }

        return ans;
    }
};
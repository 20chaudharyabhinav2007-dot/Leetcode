
class Solution {
public:
    struct BIT {
        int n;
        vector<long long> bit;

        BIT(int n) {
            this->n = n;
            bit.assign(n + 1, 0);
        }

        void update(int i, long long val) {
            while(i <= n) {
                bit[i] += val;
                i += i & -i;
            }
        }

        long long query(int i) {
            long long sum = 0;

            while(i > 0) {
                sum += bit[i];
                i -= i & -i;
            }

            return sum;
        }

        int kth(int k) {
            int pos = 0;

            for(int i = 1 << 17; i > 0; i >>= 1) {
                if(pos + i <= n && bit[pos + i] < k) {
                    k -= bit[pos + i];
                    pos += i;
                }
            }

            return pos + 1;
        }
    };

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<int> a = nums;
        sort(a.begin(), a.end());

        a.erase(unique(a.begin(), a.end()), a.end());

        int m = a.size();

        BIT cnt(m), sum(m);

        auto add = [&](int val, int v) {
            int id = lower_bound(a.begin(), a.end(), val) - a.begin() + 1;

            cnt.update(id, v);
            sum.update(id, 1LL * val * v);
        };

        auto getCost = [&]() -> long long {
            int mid = cnt.kth((x + 1) / 2);

            long long median = a[mid - 1];

            long long leftCount = cnt.query(mid);
            long long leftSum = sum.query(mid);

            long long totalSum = sum.query(m);

            return median * leftCount - leftSum
                 + (totalSum - leftSum)
                 - median * (x - leftCount);
        };

        vector<long long> cost(n - x + 1);

        for(int i = 0; i < x; i++) {
            add(nums[i], 1);
        }

        cost[0] = getCost();

        for(int i = x; i < n; i++) {
            add(nums[i - x], -1);
            add(nums[i], 1);

            cost[i - x + 1] = getCost();
        }

        const long long INF = 4e18;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        dp[0][0] = 0;

        for(int i = 1; i <= n; i++) {
            dp[i][0] = 0;

            for(int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];

                if(i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }

        return dp[n][k];
    }
};

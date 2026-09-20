class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>a = nums;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0)
                sum += a[i];
            else
                sum -= a[i];
        }
        long long ans = sum;
        vector<long long>pre(n, 0);
        for(int i = 0; i < n - 1; i++){
            if(i % 2 == 0)
                pre[i + 1] = pre[i] + a[i + 1] - a[i];
            else
                pre[i + 1] = pre[i] - a[i + 1] + a[i];
        }
        long long mx[2] = {(long long)-4e18, (long long)-4e18};
        for(int r = 1; r < n; r++){
            int l = r - 1;
            mx[0] = max(mx[0], -pre[l] + a[l]);
            mx[1] = max(mx[1], -pre[l] - a[l]);
            if(r % 2 == 0)
                ans = max(ans, sum + pre[r] + mx[0] - a[r]);
            else
                ans = max(ans, sum + pre[r] + mx[1] + a[r]);
        }
        return ans;
    }
};
class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({digitSum(nums[i]), nums[i]});
        }
        sort(v.begin(), v.end());
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = v[i].second;
        }

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }
        vector<bool> vis(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] || mp[a[i]] == i) {
                continue;
            }
            int j = i;
            int cnt = 0;
            while (!vis[j]) {
                vis[j] = true;
                j = mp[a[j]];
                cnt++;
            }
            swaps += cnt - 1;
        }
        return swaps;
    }
};
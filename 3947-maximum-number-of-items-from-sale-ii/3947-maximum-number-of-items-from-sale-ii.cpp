class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
         int n = items.size();

        vector<int> freq(n + 1, 0);

        for(int i = 0; i < n; i++)
        {
            freq[items[i][0]]++;
        }

        vector<int> cnt(n + 1, 0);

        for(int i = 1; i <= n; i++)
        {
            for(int j = i; j <= n; j += i)
            {
                cnt[i] += freq[j];
            }
        }

        vector<pair<int, int>> v;

        int mini = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            int factor = items[i][0];
            int price = items[i][1];

            int free = cnt[factor] - 1;

            mini = min(mini, price);

            v.push_back({price, free});
        }

        sort(v.begin(), v.end());

        long long ans = 0;
        long long rem = budget;

        for(auto it : v)
        {
            long long price = it.first;
            long long free = it.second;

            if(price > 2LL * mini)
                break;

            long long take = min(free, rem / price);

            ans += 2 * take;

            rem -= take * price;
        }

        ans += rem / mini;

        return ans;
    }
};
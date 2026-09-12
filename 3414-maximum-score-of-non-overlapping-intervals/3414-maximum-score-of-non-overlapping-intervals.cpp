class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int,int>> start;
        for(int i = 0; i < n; i++)
            start.push_back({intervals[i][0], i});
        sort(start.begin(), start.end());
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1, vector<pair<long long, vector<int>>>(5)
        );
        for(int i = n - 1; i >= 0; i--) {
            int id = start[i].second;
            for(int k = 1; k <= 4; k++) {
                dp[i][k] = dp[i + 1][k];
                int j = lower_bound(
                    start.begin(),
                    start.end(),
                    make_pair(intervals[id][1] + 1, 0)
                ) - start.begin();
                auto take = dp[j][k - 1];
                take.first += intervals[id][2];
                take.second.push_back(id);
                sort(take.second.begin(), take.second.end());
                if(take.first > dp[i][k].first ||
                  (take.first == dp[i][k].first &&
                   take.second < dp[i][k].second)) {
                    dp[i][k] = take;
                }
            }
        }
        return dp[0][4].second;
    }
};
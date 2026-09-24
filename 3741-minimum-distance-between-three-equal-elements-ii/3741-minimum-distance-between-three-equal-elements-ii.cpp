class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> pos(n + 1);
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            int x = nums[i];
            pos[x].push_back(i);
            if(pos[x].size() >= 3) {
                int m = pos[x].size();
                ans = min(ans, 2 * (pos[x][m - 1] - pos[x][m - 3]));
            }
        }
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};
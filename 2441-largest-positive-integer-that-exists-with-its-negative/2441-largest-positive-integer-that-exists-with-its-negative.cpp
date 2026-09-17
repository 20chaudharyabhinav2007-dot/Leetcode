class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
         unordered_set<int> s;
        for(int x : nums)
            s.insert(x);
        for(int x : nums) {
            if(x > 0 && s.find(-x) != s.end())
                ans = max(ans, x);
        }
        return ans;
    }
};
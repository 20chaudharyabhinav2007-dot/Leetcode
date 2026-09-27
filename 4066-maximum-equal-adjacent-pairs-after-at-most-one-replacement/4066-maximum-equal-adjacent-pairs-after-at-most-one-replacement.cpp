class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<long long, int>mp;
        for(int i = 0;i<n-1 ; i++){
            if(nums[i] == nums[i+1]){
                ans++;
            }else{
                long long a = nums[i];
                long long b = nums[i+1];
                mp[a*1000000001LL +b]++;
                mp[b*1000000001LL +a]++;
            }
        }
        int a = 0;
        for(auto x : mp){
            a = max(a,x.second);
        }
        return ans+a;
    }
};
class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();
            long long ans  = LLONG_MAX;
        int i = 0;
        while(i<n){
            int j= i;
            while(j<n && nums[j] == nums[i]){
                j++;
            }
            int l = j-i;
            if(i<n-1 && j>1){
                long long c = 1LL*(n-l)*(nums[i]);
                ans=min(ans,c);
            }
            i=j;
        }
        return ans;
    }
};
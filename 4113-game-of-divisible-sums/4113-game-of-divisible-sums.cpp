class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long>dp(n+2,0);
        for(int i = n-1 ; i>=0 ; i--){
            long long sum = nums[i];
            if(sum%3==0){
                dp[i] = sum-dp[i+1];
            }else{
                dp[i]=sum+dp[i+1];
            }
            if(i+1<n){
                sum = nums[i] + nums[i+1];
                if(sum%3 == 0){
                    dp[i]=max(dp[i] , sum-dp[i+2]);
                }else{
                    dp[i]=max(dp[i],sum+dp[i+2]);
                }
            }
        }
        return dp[0];
    }
};
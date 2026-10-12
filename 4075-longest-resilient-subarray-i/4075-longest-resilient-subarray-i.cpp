class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1;
        for(int i = 0 ;i<n ; i++){
            int r = nums[i]%k;
            int sum = 0;
            for(int j = i ; j<n ; j++){
                if(nums[j] % k != r){
                    break;
                }
                sum = (sum+nums[j])%k;
                if(sum == r){
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};
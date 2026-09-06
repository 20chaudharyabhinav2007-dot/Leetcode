class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int h = n/2;
        long long total = 0;
        for( int x : nums){
            total+= x;
        }
        long long firsum = 0;
        for( int i = 0; i<h ; i++){
            firsum+= nums[i];
        }
        long long ans = 0;
        for( int i=0 ; i<n ; i++){
            if(2*firsum > total){
                ans++;
            }
            firsum -= nums[i];
            firsum += nums[(h+i)%n];
        }
        return ans;
    }
};
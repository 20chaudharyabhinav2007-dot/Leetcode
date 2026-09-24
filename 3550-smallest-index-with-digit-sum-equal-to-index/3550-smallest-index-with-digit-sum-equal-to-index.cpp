class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0 ; i<nums.size() ; i++){
            int ans = 0;
            while(nums[i] !=0){
                ans+= nums[i]%10;
                nums[i] = nums[i]/10;
            }
            if(ans == i){
                return i;
            }
        }
        return -1;
    }
};
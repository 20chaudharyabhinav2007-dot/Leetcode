class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int sum2 = 0;
        for(int i = 0 ; i<nums.size()+1;i++){
            sum += i;
            if(i<nums.size()){
                sum2+=nums[i];
            }
        }
        return (sum-sum2);
    }
};
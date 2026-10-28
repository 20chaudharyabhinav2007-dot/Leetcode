class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max= 0;
        int max1 = 0 , max2 = 0;
        for(int i = 0; i<nums.size() ; i++){
            if(nums[i] == 1){
                max1++;
                if(max1>max){
                    max = max1;
                }
                max2 = 0;
            }else{
                max2++;
                max1=0;
            }
        }
        return max;
    }
};
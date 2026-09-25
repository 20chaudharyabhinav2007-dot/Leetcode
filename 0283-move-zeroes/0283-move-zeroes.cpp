class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int c = 0;
        int left =0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i] == 0){
                c++;
            }
            else{
                nums[left] = nums[i];
                left++;
            }
        }
        while(left<nums.size()){
            nums[left] = 0;
            left++;
        }
    }
};
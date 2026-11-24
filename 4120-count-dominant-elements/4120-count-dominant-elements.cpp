class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        for(int i = 0 ; i<n ; i++){
            if(n==1){
                c++;
            }
            else if(i==0){
                if(nums[i]>= nums[i+1]){
                    c++;
                }
            }else if(i==n-1){
                if(nums[i]>=nums[i-1]){
                    c++;
                }
            }
            else{
                if(2*nums[i]>=nums[i-1]+nums[i+1]){
                    c++;
                }
            }
        }
        return c;
    }
};
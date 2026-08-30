class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        sort(nums.begin(),nums.end());
        while(i<n&&nums[i] <0){
            i++;
        }
        int k = 1;
        while(i<n){
            if(nums[i] == k){
                k++;
            }
            i++;
        }
        return k;
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum=0;
        int d = 0;
        while(d<nums.size()){
            sum += nums[d];
            d++;
        }
        return sum%k;
    }
};
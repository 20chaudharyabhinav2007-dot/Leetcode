class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int count = INT_MAX;
        for(int i = 0; i<nums.size();i+=2){
            string c = to_string(nums[i])+to_string(nums[i+1]);
            int c1 = stoi(c);
            count=min(count,c1);
        }
        return count;
    }
};
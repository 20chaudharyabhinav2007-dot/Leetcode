class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int j = (nums.size())/3;
        unordered_map<int,int>freq;
        vector<int>a;
        for(int num : nums){
            freq[num]++;
        }
        for(auto it: freq){
            if(it.second>j){
                a.push_back(it.first);
            }
        }
        return a;
    }
};
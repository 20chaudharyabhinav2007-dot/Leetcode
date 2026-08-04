class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>hi;
        for(int num : nums){
            if(hi.count(num)){
                return true;
            }
        hi.insert(num);
        }
        return false;
    }
};
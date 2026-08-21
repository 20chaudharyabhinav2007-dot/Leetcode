class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int off = 50000;
        vector<int>v(100001,0);
        for(int i = 0; i<nums.size();i++){
            v[nums[i]+off]++;
        }
        int j = 0;
        for(int i = 0 ; i<v.size();i++){
            while(v[i]>0){
                nums[j] = i - off;
                j++;
                v[i] --;
            }
        }
        return nums;
    }
};
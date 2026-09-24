class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(n);
        int ans = 1;
        int count = 0;
        int pos = -1;
        for(int i = 0; i<n ; i++){
            if(nums[i]!=0){
                ans*=nums[i];
            }
            if(nums[i] == 0){
                count++;
                pos = i;
            }
        }
        if(count > 1){
            return v;
        }
        for(int i = 0 ; i<n ; i++){
            if(count == 0){
                v[i] = ans/nums[i];
            }
            if(count == 1 && i != pos){
                v[i] = 0;
            }
            if(count == 1 && i == pos){
                v[i] = ans;
            }
        }
        return v;
    }
};
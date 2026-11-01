class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        int u = 0;
        int s = 0;
        int max1 = 0;
        vector<int>n1(n,0);
        for(int i = 0 ; i<n-1 ; i++){
            max1 = max(max1,nums[i]);
            if(max1>1+i){
                n1[i] = 1;
                n1[i+1] = 1;
            }
        }
        for(int i = 0; i<n; i++){
            if(n1[i] == 1 && locked[i] == 1){
                u++;
            }
        }
        if(u>k){
            return -1;
        }
        for(int i = 0; i<n ; i++){
            for(int j = 1+i;j<n;j++){
                if(nums[i]>nums[j]){
                    s++;
                }
            }
        }
        return u+s;
    }
};
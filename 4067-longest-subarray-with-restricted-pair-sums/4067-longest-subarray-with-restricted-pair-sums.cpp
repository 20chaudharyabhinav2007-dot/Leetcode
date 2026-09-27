class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for(int i = 0; i<n ; i++){
            bitset<1001>p;
            bitset<1001>p2;
            for(int j = i ; j<n ; j++){
                int x = nums[j];
                if(p2[x]){
                    break;
                }
                if(((p<<x)&p).any()){
                    break;
                }
                p2 |=(p<<x);
                p[x]=1;
                ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};
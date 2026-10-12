class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n =nums.size();
        int ans = 1;
        int i = 0;
        while(i<n){
            int r = nums[i]%k;
            int j = i;
            while(j<n && nums[j] %k == r){
                j++;
            }
            unordered_map<int,int>o;
            o[0] = i;
            int sum = 0;
            for(int q = i ; q<j ; q++){
                sum = (sum + nums[q])%k;
                int u = (sum-r+k)%k;
                if(o.count(u)){
                    ans = max(ans,q-o[u]+1);
                }
                if(!o.count(sum)){
                    o[sum] = q+1;
                }
                
            }
            i = j;
        }
        return ans;
    }
};
class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0 ; i<n ; i++){
            long long sum = 0;
            unordered_set<int>st;
            for(int j = i ; j<n ; j++){
                sum+=nums[j];
                int r = ((nums[j]%k)+k)%k;
                st.insert((2LL*r)%k);
                int cur = ((sum%k)+k)%k;
                if(cur == 0|| st.count(cur)){
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};
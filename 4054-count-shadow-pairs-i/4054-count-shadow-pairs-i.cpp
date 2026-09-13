class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        vector<int> st;
        long long ans = 0;
        for(int x : nums){
            while(!st.empty() && st.back() > x){
                st.pop_back();
            }
            int l = 0, r = st.size();
            while(l < r){
                int mid = l + (r - l) / 2;
                if(st[mid] < x){
                    l = mid + 1;
                }
                else{
                    r = mid;
                }
            }
            ans += l;
            st.push_back(x);
        }
        return ans;
    }
};
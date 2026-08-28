class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        set<int>st;
        for(int i : nums1){
            st.insert(i);
        }
        for(int i: nums2){
            if(st.count(i)){
                ans.push_back(i);
                st.erase(i);
            }
        }
        return ans;
    }
};
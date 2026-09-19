class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> a(101, 0);
        vector<int> b(101, 0);
        vector<int> c(101, 0);
        for(int i = 0; i < nums1.size(); i++)
            a[nums1[i]] = 1;
        for(int i = 0; i < nums2.size(); i++)
            b[nums2[i]] = 1;
        for(int i = 0; i < nums3.size(); i++)
            c[nums3[i]] = 1;
        vector<int> ans;
        for(int i = 1; i <= 100; i++) {
            if(a[i] + b[i] + c[i] >= 2)
                ans.push_back(i);
        }
        return ans;
    }
};
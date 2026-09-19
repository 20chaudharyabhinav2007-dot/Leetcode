class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = nums[0];
        int mx = nums[0];
        for (int x : nums) {
            mn = min(mn, x);
            mx = max(mx, x);
        }
        vector<int> missing;
        for (int i = mn; i <= mx; i++) {
            bool found = false;

            for (int x : nums) {
                if (x == i) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                missing.push_back(i);
            }
        }
        return missing;
    }
};
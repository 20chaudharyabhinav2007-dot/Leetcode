class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int o = 0;
        for (int num : nums) {
            int n = k - num;
            if (freq[n] > 0) {
                o++;
                freq[n]--;
            } else {
                freq[num]++;
            }
        }
        return o;
    }
};
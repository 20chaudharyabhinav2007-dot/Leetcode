class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int freq[101] = {0};
        int sum = 0;
        for (int x : nums) {
            freq[x]++;
        }
        for (int x : nums) {
            if (freq[x] == 1) {
                sum += x;
            }
        }
        return sum;
    }
};
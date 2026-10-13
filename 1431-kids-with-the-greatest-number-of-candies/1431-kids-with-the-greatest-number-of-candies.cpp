class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m = *max_element(candies.begin(), candies.end());
        vector<bool>r;
        for (int i = 0; i < candies.size(); i++) {
            r.push_back(candies[i] + extraCandies >= m);
        }
        return r;
    }
};
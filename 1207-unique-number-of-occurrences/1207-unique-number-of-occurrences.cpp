class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        set<int> s;
        for (int x : arr) {
            freq[x]++;
        }
        for (auto x : freq) {
            s.insert(x.second);
        }
        return s.size() == freq.size();
    }
};
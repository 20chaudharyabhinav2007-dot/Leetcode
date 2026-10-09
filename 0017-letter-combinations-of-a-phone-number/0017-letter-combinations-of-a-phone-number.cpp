class Solution {
public:
    vector<string> ans;
    string temp;
    string mp[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void solve(string &digits, int index) {
        if (index == digits.size()) {
            ans.push_back(temp);
            return;
        }
        string letters = mp[digits[index] - '0'];
        for (char c : letters) {
            temp.push_back(c);
            solve(digits, index + 1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        solve(digits, 0);
        return ans;
    }
};
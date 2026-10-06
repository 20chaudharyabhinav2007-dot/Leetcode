class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>t;
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                t.push(s[i]);
            }
            if(s[i] == ')') {
                if(t.empty()) {
                    ans++;
                }
                else {
                    t.pop();
                }
            }
        }
        return ans + t.size();
    }
};
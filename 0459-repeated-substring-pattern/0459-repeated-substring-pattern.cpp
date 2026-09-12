class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int len = 1; len <= n/2; len++) {
            if(n % len != 0)
                continue;
            bool p = true;
            for(int i = len; i < n; i++) {
                if(s[i] != s[i % len]) {
                    p = false;
                    break;
                }
            }
            if(p)
                return true;
        }
        return false;
    }
};
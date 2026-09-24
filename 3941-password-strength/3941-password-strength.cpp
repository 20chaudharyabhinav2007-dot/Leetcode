class Solution {
public:
    int passwordStrength(string password) {
        vector<int> v(128, 0);
        int ans = 0;
        for(char c : password) {
            if(v[c] == 1) continue;
            v[c] = 1;
            if(c >= 'a' && c <= 'z')
                ans += 1;
            else if(c >= 'A' && c <= 'Z')
                ans += 2;
            else if(c >= '0' && c <= '9')
                ans += 3;
            else
                ans += 5;
        }
        return ans;
    }
};
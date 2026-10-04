class Solution {
public:
    int minRotations(string s) {
        int c = 0;
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            int k = s[i]-'0';
            int temp = abs(c-k);
            ans+=min(temp,10-temp);
            c=k;
        }
        return ans;
    }
};
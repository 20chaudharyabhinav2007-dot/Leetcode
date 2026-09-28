class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        stack<char>m;
        int ans = 0;
        for(int i = 0; i<n ; i++){
            if(s[i] == '('){
                m.push(s[i]);
            }
            ans = max(ans,(int)m.size());
            if(s[i] == ')'){
                m.pop();
            }
        }
        return ans;
    }
};
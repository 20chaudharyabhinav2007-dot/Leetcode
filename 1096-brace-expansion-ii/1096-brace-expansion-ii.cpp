class Solution {
public:
    set<string> solve(string &s, int &i) {
        set<string> ans;
        set<string> curr = {""};
        while (i < s.size() && s[i] != '}') {
            if (s[i] == ',') {
                for (string x : curr)
                    ans.insert(x);
                curr = {""};
                i++;
            }
            else if (s[i] == '{') {
                i++;
                set<string> temp = solve(s, i);
                i++;
                set<string> next;
                for (string a : curr) {
                    for (string b : temp) {
                        next.insert(a + b);
                    }
                }
                curr = next;
            }
            else {
                string ch(1, s[i]);
                i++;
                set<string> next;
                for (string x : curr)
                    next.insert(x + ch);
                curr = next;
            }
        }
        for (string x : curr)
            ans.insert(x);
        return ans;
    }
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans = solve(expression, i);
        return vector<string>(ans.begin(), ans.end());
    }
};
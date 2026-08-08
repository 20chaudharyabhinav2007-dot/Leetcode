class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        int j = 0;
        string ans ="";
        for(i = 0 ; i<strs[0].length() ; i++){
            for(j = 1; j<strs.size();j++){
                if(i >= strs[j].length() || strs[0][i] != strs[j][i]){
                    return ans;
                }
            }
            ans+=strs[0][i];
        }
        return ans;
    }
};
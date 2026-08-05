class Solution {
public:
    bool detectCapitalUse(string word) {
        int upper = 0;
        for(int i = 0 ; i<word.length() ; i++){
            if(isupper(word[i])){
                upper++;
            }
        }
        return upper == word.length() || upper == 0 || upper == 1 && isupper(word[0]);
    }
};
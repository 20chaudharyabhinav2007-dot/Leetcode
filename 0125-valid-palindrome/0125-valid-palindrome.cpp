class Solution {
public:
    bool isPalindrome(string s) {
        bool n = true;
        string m = "";
        for(int i = 0; i<s.size(); i++){
            if(isalnum(s[i])){
                m += tolower(s[i]);
            }
        }
        int left = 0;
        int right = m.size()-1;
        while(left<=right){
            if(m[left] != m[right]){
                n = false;
                break;
            }
            left++;
            right--;
        }
        return n;
    }
};
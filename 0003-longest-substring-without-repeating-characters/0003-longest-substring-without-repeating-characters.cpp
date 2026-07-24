class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> c;
        int left = 0;
        int ans = 0;
        for(int right = 0; right<s.size();right++){
            while(c.count(s[right])){
                c.erase(s[left]);
                left++;
            }
            c.insert(s[right]);
            ans = max(ans,right-left+1);
        }
        
        return ans;

        
    }
};
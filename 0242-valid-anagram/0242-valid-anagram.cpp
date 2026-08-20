class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<char>asc;
        vector<char>asc2;
        if(n != m){
            return false;
        }
        else{
            for(int i = 0 ; i<n ; i++){
                asc.push_back(s[i]);
            }
            for(int i = 0 ; i<m ; i++){
                asc2.push_back(t[i]);
            }
            sort(asc.begin(),asc.end());
            sort(asc2.begin(),asc2.end());
            int count = 0;
            for(int i = 0 ; i<n ; i++){
                if(asc[i] != asc2[i]){
                    count++;
                    break;
                }
            }
            if(count == 0){
                return true;
            }
            else{
                return false;
            }
        }
    }
};
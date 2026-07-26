class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()){
            return"";
        }
        string t="#";
        for(char c : s){
            t+=c;
            t+="#";
        }
        int right = 0;
        int centerindex = 0;
        int centre =0;
        int  maxl = 0;
        int n = t.size(); 
        vector<int>p(n,0);
        for(int i = 0 ; i<t.size();i++){ 
            int mirror = 2*centre - i;
            if(i < right){
                p[i]= min(right - i , p[mirror]);
            }
            while(i-p[i]-1>=0 && i+p[i]+1<n &&t[i-p[i]-1] == t[i+p[i]+1]){
                p[i]++;
            }
            if(i+p[i]>right){
                centre = i;
                right = i+p[i];
            }
            if(p[i]>maxl){
                centerindex = i;
                maxl = p[i];
            }
            
        }
        int start = (centerindex - maxl)/2;
        return s.substr(start , maxl);      
        }
        
    
};
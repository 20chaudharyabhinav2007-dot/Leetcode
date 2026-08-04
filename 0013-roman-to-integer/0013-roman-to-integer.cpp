class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        unordered_map<char,int>symbol = {
            {'I' , 1} , {'V' , 5} , {'X',10} , {'L',50} , {'C',100} , {'D',500} , {'M',1000}
        };
        for(int i = 0; i<s.length() ; i++){
          if( i+1 < s.length() && symbol[s[i]]<symbol[s[i+1]]){
            ans -= symbol[s[i]];
          }else{
            ans+= symbol[s[i]];
          }
        }
        return ans;
    }
};
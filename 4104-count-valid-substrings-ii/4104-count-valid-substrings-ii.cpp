class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        int last = -1;
        int a = -1, b=-1;
        long long ans = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == 'a'){
                a=i;
            }
            if(s[i] == 'b' && a!=-1){
                b=a;
            }
            if(s[i] == 'c' && b!=-1){
                last=b;
            }
            ans+=i-last;
        }
        return ans;
    }
};
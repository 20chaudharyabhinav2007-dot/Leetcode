class Solution {
public:
    int minRotations(int n, string s) {
        vector<int>s1(n+1,0);
        vector<int>s2(n+1,0);
        for(int i = 0; i<n ;i++){
            int a = (i==0?0:s[i-1]-'0');
            int b = s[i] - '0';
            int temp = abs(a-b);
            s1[i+1] = s1[i]+min(temp,10-temp); 
        }
        for(int i = n-2 ; i>=0 ; i--){
            int a = s[i]-'0';
            int b = s[i+1]-'0';
            int temp = abs(a-b);  
            s2[i] = s2[i+1]+min(temp , 10-temp);
        }
        int ans = s1[n];
        for(int i = 0;i<n;i++){
            int last = s[n-1]-'0';
            int p = (i==0 ? 0:s[i-1]-'0');
            int temp = abs(p-last);
            int c = min(temp , 10-temp);
            ans = min(ans,s1[i]+c+s2[i]);
        }
        return ans;
    }
};
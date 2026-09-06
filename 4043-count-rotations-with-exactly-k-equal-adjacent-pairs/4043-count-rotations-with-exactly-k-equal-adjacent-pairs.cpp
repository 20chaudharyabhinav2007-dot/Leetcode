class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int i = 0;
        int ans = 0;
        for(i = 0; i<n ; i++){
            string r = s.substr(i)+s.substr(0,i);
            int l = 0;
            for(int j = 0;j<n-1;j++){
                if(r[j] == r[j+1]){
                    l++;
                }
            }
            if(k == l){
                ans++;
            }
        }
        return ans;
    }
};
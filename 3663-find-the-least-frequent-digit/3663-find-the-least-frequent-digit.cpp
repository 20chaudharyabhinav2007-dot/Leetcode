class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int>v(10,0);
        while(n!=0){
            v[n%10]++;
            n=n/10;
        }
        int ans_1 = 0;
        int ans = 1000000;
        for(int i = 0;i<v.size();i++){
            if(v[i] != 0 && v[i] < ans) {
                ans = v[i];
                ans_1 = i;
            }
        }
        return ans_1;
    }
};
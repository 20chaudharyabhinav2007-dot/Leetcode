class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<bool> i(n+1,true);
        i[0] = i[1] = false;
        for(int it = 2 ; it*it<=n ; it++){
            if(i[it]){
                for(int j = it*it ; j<=n ; j+=it){
                    i[j] = false;
                }
            }
        }
        vector<int> ans;
        for(int it = 2 ; it<=n ; it++){
            if(i[it]){
                if(s<it){
                    break;
                }
                ans.push_back(it);
                s-=it;
            }
        }
        return ans;
    }
};
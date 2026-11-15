class Solution {
public:
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();
        vector<vector<int>>a(n);
        for(int i = 1 ; i<n ; i++){
            a[parent[i]].push_back(i);
        }
        vector<int>o;
        vector<int>o1;
        o1.push_back(0);
        while(!o1.empty()){
            int node = o1.back();
            o1.pop_back();
            o.push_back(node);
            for(int c : a[node]){
                o1.push_back(c);
            }
        }
        vector<long long>dp(n,0);
        for(int i = n-1 ; i>=0 ; i--){
            int node = o[i];
            long long sum = 0;
            long long m = LLONG_MAX;
            for(int c : a[node]){
                sum+=dp[c];
                m=min(m,dp[c]);
            }
            if(a[node].empty()){
                dp[node] = score[node];
            }else if(op[node] == 0){
                dp[node] = score[node] + sum - min(0LL,m);
            }else{
                dp[node] = score[node]+sum-m;
            }
        }
        return dp[0];
    }
};
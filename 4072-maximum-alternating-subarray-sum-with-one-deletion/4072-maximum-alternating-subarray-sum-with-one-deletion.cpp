class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long N = LLONG_MIN;
        long long p = N;
        long long p1 = N;
        long long m= N;
        long long m1 = N;

        long long ans = N;
        for(int x : nums){
            long long n = x;
            long long q = N;
            long long n1 = x;
            long long q1 = N;
            if(m!= N){
                n = max(n,m+x);
            }
            if(p !=N){
                q = p-x;
            }
            if(m1 !=N){
                n1 = max(n1,m1+x);
            }
            if(p != N){
                n1 = max(n1 , p);
            }
            if(p1!=N){
                q1 = max(q1,p1-x);
            }
            if(m!=N){
                q1 = max(q1 , m);
            }
            p = n;
            m = q;
            p1 = n1;
            m1 = q1;
            ans = max(ans,max(max(p,m),max(p1,m1)));
        }
        return ans;
    }
};
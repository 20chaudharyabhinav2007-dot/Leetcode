class Solution {
public:
    bool threeFibonacciSum(int n) {
        long long a = 0 , b = 1 , c=1;
        while(a+b+c <= n){
            if(a+b+c == n){
                return true;
            }
            a = b;
            b=c;
            c=a+b;
        }
        return false;
    }
};
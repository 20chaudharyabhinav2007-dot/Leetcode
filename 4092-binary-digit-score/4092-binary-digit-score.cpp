class Solution {
public:
    int calculateScore(int a, int b) {
        int x = __builtin_popcount(a);
        int y = __builtin_popcount(b);
        if(x>=y){
            return x*y;
        }else{
            return y/x;
        }
    }
};
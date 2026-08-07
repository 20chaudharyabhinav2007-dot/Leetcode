class Solution {
public:
    int smallestNumber(int n, int t) {
        int number = n;
        while(true){
            int p = 1;
            n = number;
            while(n>0){
                p *= n%10;
                n/=10;
            }
            if(p%t == 0){
                break;
            }else{
                number++;
            }
        }
        return number;
    }
};
class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if(value == 1){
            return -1;
        }
        int a = value;
        for(int i = 2; i*i<=value;i++){
            if(value%i == 0){
                a = i;
                break;
            }
        }
        if(index > (value-a)/2){
            return -1;
        }
        int b = n-1-index;
        if(b==0){
            return value;
        }
        return(long long)value+a+2LL*(b-1);
    }
};
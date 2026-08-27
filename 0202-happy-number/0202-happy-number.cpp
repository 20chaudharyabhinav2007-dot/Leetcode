class Solution {
public:
    int cal(int n){
        int s = 0;
        while(n!=0){
            s += (n%10)*(n%10);
            n = n/10;
        }
        return s;
    }
    bool isHappy(int n) {
        set<int>number;
        while(n!=1){
            if(number.count(n)){
                return false;
            }
            number.insert(n);
            n = cal(n);
        }
        return true;
    }
};
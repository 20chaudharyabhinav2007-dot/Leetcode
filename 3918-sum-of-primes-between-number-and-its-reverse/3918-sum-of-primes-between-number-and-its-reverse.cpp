class Solution {
public:
    bool prime(int n) {
        if(n < 2){
            return false;
        }
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        int r = 0;
        int x = n;
        while(x > 0) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        int low = min(n, r);
        int high = max(n, r);
        long long sum = 0;
        for(int i = low; i <= high; i++) {
            if(prime(i)) {
                sum += i;
            }
        }
        return sum;
    }
};
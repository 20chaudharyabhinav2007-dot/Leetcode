class Solution {
public:
    int addDigits(int num) {
        int m = num;
        while(num >= 10) {
            m = 0;
            while(num != 0) {
                m += num % 10;
                num = num / 10;
            }
            num = m;
        }
        return m;
    }
};
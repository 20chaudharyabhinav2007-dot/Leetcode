class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>v;
        while(left<=right){
            int s = left;
            bool t = true;
            while(s != 0){
                int d = s % 10;
                if(d == 0 || left % d != 0) {
                    t = false;
                    break;
                }
                s /= 10;
            }
            if(t == true){
                v.push_back(left);
            }
            left++;
        }
        return v;
    }
};
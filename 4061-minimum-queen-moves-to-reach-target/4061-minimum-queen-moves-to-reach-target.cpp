class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int s = source[0];
        int s1 = source[1];
        int t = target[0];
        int t1 = target[1];
        if(s ==t && s1 == t1){
            return 0;
        }
        if(s ==t || s1 == t1){
            return 1;
        }
        if(abs(s-t) == abs(s1-t1)){
            return 1;
        }
        return 2;
    }
};
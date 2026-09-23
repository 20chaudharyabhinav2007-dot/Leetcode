class Solution {
public:
    int minimumFlips(int n) {
        vector<int>v;
        while(n>0){
            v.push_back(n%2);
            n = n/2;
        }
        int left = 0;
        int right = v.size()-1;
        int count = 0;
        while(left != v.size()){
            if(v[left] != v[right]){
                count++;
            }
            right--;
            left++;
        }
        return count;
    }
};
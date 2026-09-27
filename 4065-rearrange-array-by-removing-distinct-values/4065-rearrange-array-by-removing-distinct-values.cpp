class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;
        int freq[101]={0};
        for(int x : nums){
            freq[x]++;
        }
        while(ans.size() < nums.size()){
            for(int i = 1 ; i<=100 ; i++){
                if(freq[i] > 0){
                    ans.push_back(i);
                    freq[i]--;
                }
            }
        }
        return ans;
    }
};
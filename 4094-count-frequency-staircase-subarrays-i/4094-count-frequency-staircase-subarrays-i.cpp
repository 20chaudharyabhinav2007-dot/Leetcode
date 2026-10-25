class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<n ; i++){
            unordered_map<int, int> freq;
            int dist = 0;
            vector<int> order;
            bool val = true;
            for(int j =i; j<n ; j++){
                int x = nums[j];
                freq[x]++;
                if(freq[x] == 1){
                    dist++;
                    order.push_back(x);
                }
                if(freq[x]>dist){
                    break;
                }
                val = true;
                for(int t = 0; t< dist ; t++){
                    if(freq[order[t]] != t+1){
                        val=false;
                        break;
                    }
                }
                if(val){
                    ans++;
                }
            }
        }
        return ans;
    }
};
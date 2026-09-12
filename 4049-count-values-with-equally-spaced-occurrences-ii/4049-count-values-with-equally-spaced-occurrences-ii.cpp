class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int,vector<int>>mp;
        for(int i = 0; i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int ans = 0;
        for(auto &p :mp){
            vector<int>v  = p.second;
            if(v.size()<3){
                continue;
            }
            int g = v[1] - v[0];
            bool t = true;
            for(int i = 2 ; i<v.size() ; i++){
                if(v[i] - v[i-1] != g){
                    t = false;
                    break;
                }
            }
            if(t){
                ans++;
            }
        }
        return ans;
    }
};
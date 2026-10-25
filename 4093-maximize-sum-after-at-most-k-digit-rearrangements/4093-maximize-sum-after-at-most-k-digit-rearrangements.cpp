class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        vector<int>s1;
        long long sum = 0;
        for(int i= 0 ; i<nums.size() ; i++){
            sum+= nums[i];
            string s = to_string(nums[i]);
            sort(s.begin(),s.end(),greater<char>());
            int v = stoi(s);
            s1.push_back(v-nums[i]);
        }
        sort(s1.rbegin(), s1.rend());
        for(int i = 0; i<k ; i++){
            sum+=s1[i];
        }
        return sum;
    }
};
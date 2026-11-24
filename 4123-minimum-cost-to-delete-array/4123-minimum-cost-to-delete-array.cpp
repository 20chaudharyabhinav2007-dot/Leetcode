class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        long long sum = nums[0]+1LL*nums[n-1];
        long long s = 0;
        int c = 0;
        int neg = INT_MAX;
        int pos = INT_MAX;
        bool t = false;
        for(int i = 1 ; i<n-1 ; i++){
            if(nums[i]<0){
                s+=nums[i];
                c++;
                neg=min(neg,-nums[i]);
            }else if(nums[i]>0){
                pos=min(pos,nums[i]);
            }else{
                t=true;
            }
        }
    if(c%2!=0 && !t){
        s+=min(neg,pos);
    }
        return sum+s;
    }
};
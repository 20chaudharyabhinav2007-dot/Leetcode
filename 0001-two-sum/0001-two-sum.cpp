class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> arr;
        for(int i = 0; i< nums.size();i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        int left = 0;
        int right = nums.size()-1;
        while(left<right){
            int n = arr[left].first+arr[right].first;
            if(target == n){
                return {arr[left].second, arr[right].second};
            }else if(target > n){
                left++;

            }else{
                right--;
                }  
                  }
        
        return{};
    }
};
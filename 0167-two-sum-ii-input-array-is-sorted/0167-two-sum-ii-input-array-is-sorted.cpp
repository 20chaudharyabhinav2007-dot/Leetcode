class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<pair<int,int>> arr;
        for(int i = 0; i< numbers.size();i++){
            arr.push_back({numbers[i],i+1});
        }
        int left = 0;
        int right = numbers.size()-1;
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
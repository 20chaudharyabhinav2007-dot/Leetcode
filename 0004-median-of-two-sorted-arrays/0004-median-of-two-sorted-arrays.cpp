class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int a = 0;
        int b = 0;
        vector<int>merge;
        while(a<m && b <n ){
            if(nums1[a]<nums2[b]){
                merge.push_back(nums1[a]);
                a++;
            }else{
                merge.push_back(nums2[b]);
                b++;
            }
        }
        while(a<m){
            merge.push_back(nums1[a]);
            a++;
        }
        while(b<n){
            merge.push_back(nums2[b]);
            b++;
        }
        int tot = merge.size();
        if(tot%2 != 0){
            return merge[tot/2];
        }else{
            return (merge[tot/2 -1]+merge[tot/2])/2.0;
        }        
    }
};
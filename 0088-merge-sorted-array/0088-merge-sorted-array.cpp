class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector <int> array(m+n);
        int i = 0;
        int j = 0;
        int k = 0;
        while ( i < m && j < n && k< m+n){
            if(nums1[i]<nums2[j]){
                array[k]=nums1[i];
                i++;
                k++;
            }else{
                array[k]=nums2[j];
                j++;
                k++;
            }
            }
            while(i<m){
                array[k] = nums1[i];
                k++;
                i++;
            }
            while(j<n){
                array[k] = nums2[j];
                k++;
                j++;
        }
        for(int i = 0; i < m + n; i++){
            nums1[i] = array[i];
        }
    }
};
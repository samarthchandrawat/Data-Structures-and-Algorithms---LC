class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int i=0;
        int j=0;
        
        vector<int> merged_arr;
        
        while(i<nums1.size() && j<nums2.size()){
        
            if(nums1[i] < nums2[j]) {
                merged_arr.push_back(nums1[i]);
                i++;
            } else {
                merged_arr.push_back(nums2[j]);
                j++;
            }
        }
        
        while(i < nums1.size()) {
            merged_arr.push_back(nums1[i]);
            i++;
        }
        
        while(j < nums2.size()) {
            merged_arr.push_back(nums2[j]);
            j++;
        }
        
        int tot = nums1.size() + nums2.size();
        
        double two = 2, res;
        
        if(tot%2 == 0) {
            return (merged_arr[(tot/2)-1] + merged_arr[(tot/2)])/two;
        } else {
            return(merged_arr[tot/2]);
        }
        
        return res;
    }
};
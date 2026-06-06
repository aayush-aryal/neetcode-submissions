class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        while (l<=r){
            int mid=(l+r)/2;
            if (target==nums[mid]){
                return mid;
            }
            // if array is rotated [3,4,5,6,1,2] target =1
            // search the right if -> target<l and nums[r]<nums[l]
            if (nums[l]<=nums[mid]){
                // we know that the left half is sorted and right half might not be
                if (nums[l]<=target && target<=nums[mid]){
                    r=mid-1;
                }else{
                    l=mid+1;
                }   
            }else{
                
                // we know the right half is sorted
                if (nums[mid]<=target && target<=nums[r] ){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
        }
        return -1;  
    }
};

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // seems like a sliding window problem
        int l=0;
        int r=0;
        int min= nums[0];
        int max=nums[0];
        int curr=0;
        int maximum=0;

        while (r<nums.size()){
            // if at the current position max-min <limit add to the count
            for (int i=l; i<=r; i++){
                min=std::min(min,nums[i]);
                max=std::max(max,nums[i]);
            }
            while (max-min>limit && l<r){
                l+=1;
                min=nums[l];
                max=nums[l];
                for (int j=l; j<r; j++){
                    min=std::min(nums[j],min);
                    max=std::max(nums[j],max);
                }
            }
            curr=r-l+1;
            maximum=std::max(curr,maximum);
            r+=1;
        }
        return maximum;
        
        
    }
};
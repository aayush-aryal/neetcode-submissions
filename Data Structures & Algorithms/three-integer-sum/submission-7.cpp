class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // three sum is 2 sum with 1 fixed i
        // we sort the input so we can use two pointers
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        std::unordered_map<int,int> f;
        for (int i=0; i<nums.size();i++){
            int l=i+1;
            int r=nums.size()-1;
            // handle duplicates here
            if (i>0 && nums[i]==nums[i-1]){
                continue;
            }
            while (l<r){
                if (nums[i]+nums[l]+nums[r]==0){
                    res.push_back({nums[i],nums[l],nums[r]});
                    // now update the poitner to the next non duplicate
                    l++;
                    r--;
                    while (l<r && nums[l]==nums[l-1]){
                        l++;
                    }
                    while (r>0 && nums[r]==nums[r+1]){
                        r--;
                    }
                }else{
                    if (nums[i]+nums[l]+nums[r]>0){
                    r--;
                }
                if (nums[i]+nums[l]+nums[r]<0){
                    l++;
                }

                }
            }
        }
        return res;
        
    }
};

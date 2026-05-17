class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // distinct pairs, since the array is unsorted sort it first
        sort(nums.begin(),nums.end());
        // intuition says to do the two sum problem with a fixed num with 0 as target
        int l=0;
        int arrSize=nums.size();
        int r=arrSize-1;
        vector <vector<int>> triplets={};
        for (int i=0; i<nums.size();i++){
            // since i is our fixed spot l begins at i+1
            l=i+1;
            r=arrSize-1;
            // check for duplicate
            if (i>0 and nums[i]==nums[i-1]){
                continue ;
            }
            while (l<r){
                // if they are a valid triplet
                int sum=nums[i]+nums[l]+nums[r];
                if (sum==0){
                    triplets.push_back({nums[i],nums[l],nums[r]});
                    l+=1;
                    r-=1;
                    while (l<r && nums[l]==nums[l-1]){
                        l+=1;
                    }
                    while (r>0 && nums[r]==nums[r+1]){
                        r-=1;
                    } 
                }else{
                    // after we jave pushed the triplet in we need to find a new l and r
                    if (sum>0){
                        r-=1;
                    }else{
                        l+=1;
                    }
                }
            }
        }
        return triplets;
    }
};

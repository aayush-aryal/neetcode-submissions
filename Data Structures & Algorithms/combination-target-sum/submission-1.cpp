class Solution {
public:
    vector<int> subset;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(0,nums,target,0);
        return res;

        
    }

    void backtrack(int i, vector<int>& nums, int target, int currSum){
        // base cases
        if (i>=nums.size()){
            return;
        }
        if ( currSum== target){
            res.push_back(subset);
            return;
        }
        if (currSum>target){
            return;
        }
        // fir each number in nums we can
        // include it as a sum to our final total
        // not include it 

        currSum+=nums[i];
        subset.push_back(nums[i]);
        backtrack(i,nums,target,currSum);
        currSum-=nums[i];
        subset.pop_back();
        backtrack(i+1,nums,target,currSum);
    }
};

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
            if (std::find(res.begin(),res.end(),subset)==res.end()){
                res.push_back(subset);

            }
            return;
        }
        if (currSum>target){
            return;
        }
        // fir each number in nums we can
        // add to curr sum and try backtracking with whole nums
        // skip curr num and try backtracking with that

        currSum+=nums[i];
        subset.push_back(nums[i]);
        backtrack(i,nums,target,currSum);
        backtrack(i+1,nums,target,currSum);
        currSum-=nums[i];
        subset.pop_back();
        backtrack(i+1,nums,target,currSum);
    }
};

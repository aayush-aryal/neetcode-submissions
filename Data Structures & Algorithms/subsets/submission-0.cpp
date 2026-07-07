class Solution {
public:
    // at every possible index we have an option to either include or not include a number
    vector<vector<int>> res;
    vector<int> subset;
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0,nums.size(),nums);
        return res;  
    }
    void dfs(int i, int size, vector<int>& nums){
            if (i>=size){
                res.push_back(subset);
                return;
            }
            subset.push_back(nums[i]);
            dfs(i+1,size,nums);
            subset.pop_back();
            dfs(i+1,size,nums);
    }



    
};

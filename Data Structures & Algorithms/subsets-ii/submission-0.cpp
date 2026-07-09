class Solution {
public:
    vector<int> subset;
    vector<vector<int>> result;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        bt(0,nums);
        return result;

        
    }

    void bt(int i, vector<int>& nums){
        result.push_back(subset);
        for (int j=i; j<nums.size();j++){
            if (j>i && nums[j-1]==nums[j]){
                continue;
            }
            subset.push_back(nums[j]);
            bt(j+1,nums);
            subset.pop_back();
        }
    }    
};

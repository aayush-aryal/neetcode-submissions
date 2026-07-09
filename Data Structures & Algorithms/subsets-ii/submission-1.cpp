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
        if (i>=nums.size()){
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        bt(i+1,nums);
        subset.pop_back();

        int next=i+1;
        while (next<nums.size()&& nums[next]==nums[i]){
            next++;
        }
        bt(next,nums);
    }    
};

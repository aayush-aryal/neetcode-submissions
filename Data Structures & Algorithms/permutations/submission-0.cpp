class Solution {
public:
    vector<vector<int>> result;
    vector<int> subset;
    vector<vector<int>> permute(vector<int>& nums) {
        bt(nums);
        return result;
        
    }

    void bt(vector<int>& nums){
        if (subset.size()==nums.size()){
            result.push_back(subset);
            return;
        }
        for(int j=0; j<nums.size();j++){
            if (std::find(subset.begin(),subset.end(),nums[j])== subset.end()){
                subset.push_back(nums[j]);
                bt(nums);
                subset.pop_back();
            }
        }    
    }
};

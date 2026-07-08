class Solution {
public:
vector<vector<int>> res;
vector<int> subset;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        bt(0,target,0,candidates);
        return res;


        
    }

    void bt(int i, int target, int currSum, vector<int>& candidates){
        // we know
    if (currSum == target) {
            res.push_back(subset);
            return;
        }

    if (currSum > target)
        return;


        // if we include one index we cannot include it again
        // so two options include the index and move on
        // or dont inlcud ethe index and move on
        for (int j=i; j<candidates.size();j++){
            if (j>i&& candidates[j-1]==candidates[j]){
                continue;
            }
            if (candidates[j]>target){
                break;
            }
            subset.push_back(candidates[j]);
            bt(j + 1,target,currSum+candidates[j], candidates);
            subset.pop_back();
        }
    }

};

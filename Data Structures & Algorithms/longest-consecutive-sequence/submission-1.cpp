using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        //unordered_set<int> allSeq(nums.begin(), nums.end());
        unordered_set <int> allSeq;
        for (int i=0; i<nums.size();i++){
            allSeq.insert(nums[i]);
        }
        int longest=0;
        int currSeq=0;
        for (int j=0; j<nums.size();j++){
            if (!allSeq.contains(nums[j]-1)){
                currSeq=0;
                int curr=nums[j];
                while (allSeq.contains(curr)){
                    currSeq=currSeq+1;
                    curr+=1;
                }
                longest=max(longest,currSeq);

            }
            
        }

        return longest;

        
    }
};

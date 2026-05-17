using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //cpp
        unordered_map<int, int> hashMap;
        for (int i; i<nums.size();i++){
            int difference= target- nums[i];
            if (hashMap.find(difference)!=hashMap.end()){
                return {hashMap[difference],i};
            }
            hashMap[nums[i]]=i;
        }
        return {};
    }
};

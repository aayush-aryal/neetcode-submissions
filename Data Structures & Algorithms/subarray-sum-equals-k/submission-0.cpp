class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        std::unordered_map<int,int> freq;
        freq[0]=1;
        int sum=0;
        int ans=0;
        for (int n:nums){
            sum+=n;
            ans+=freq[sum-k];
            freq[sum]++;
        }
        return ans;
    }
};
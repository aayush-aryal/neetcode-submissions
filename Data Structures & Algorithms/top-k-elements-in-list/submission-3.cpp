class Solution {
public:
    std::unordered_map<int, int> f;
    std::vector<int> res;
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        makeMap(nums);
        std::vector<std::vector<int>>buckets(nums.size()+1);
        for (auto& [k,v]: f){
            buckets[v].push_back(k);
        }
        for (int i= buckets.size()-1;i>0;i--){
            for (int n: buckets[i]){
                res.push_back(n);
                if (res.size()==k){
                    return res;
                }
            }
        }
        return res;
        
    }

    void makeMap(vector<int>& nums){
        for (int n:nums){
            if (f.find(n)==f.end()){
                f[n]=1;
            }else{
                f[n]++;
            }
        }
    }
};

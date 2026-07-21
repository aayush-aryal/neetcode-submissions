class Solution {
public:
    vector<string> res;
    string subs;
    unordered_map<char, string> f{
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};
    vector<string> letterCombinations(string digits) {
        dfs(digits,0);
        return res;
    
    }

    void dfs(string digits,int i){
        if (digits==""){
            return;
        }
        if (i>=digits.size()){
            res.push_back(subs);
        }
        for (int j=0; j<f[digits[i]].size();j++){
            // for each of these we can choose to either include this or not include it
            subs.push_back(f[digits[i]][j]);
            dfs(digits,i+1);
            subs.pop_back();
        }
    }
};

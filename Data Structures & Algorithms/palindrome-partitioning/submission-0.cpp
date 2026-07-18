class Solution {
public:
    vector<vector<string>> res;
    vector<string> subset;
    vector<vector<string>> partition(string s) {
        dfs(0,s);
        return res;
        
    }

    // palindrome partitioning
    void dfs(int i, string& s){
        if (i>=s.size()){
            res.push_back(subset);
            return;
        }  

        for (int j=i; j<s.size();j++){
            if (isPalindrome(i,j,s)){
                subset.push_back(s.substr(i,j-i+1));
                dfs(j+1,s);
                subset.pop_back();
            }
        } 
    }

    // helper ?
    bool isPalindrome(int l,int r,string& s){
        while (l<r){
            if (s[l]!=s[r]){
                return false;
            }
            l+=1;
            r-=1;
        }
        return true;
    }
};

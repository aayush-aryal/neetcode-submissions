class Solution {
public:
    string sub;
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        bt(0,0,n);
        return result;
        
    }
    // well formed parantheses ie "()"
    // for every open there has to be a close
    // seems like a stack problem? ie valid paranthesis
    // open close problem?
    // when can we ((( , when its less than n
    // when can we close? if close < open


    void bt(int open, int close, int n){
        if (open==close && open==n){
            result.push_back(sub);
            return;
        }
        if (open<n){
            // append to a string here append a open paranthesis
            sub.push_back('(');
            bt(open+1,close,n);
            sub.pop_back();
        }
        if (close<open){
            sub.push_back(')');
            bt(open,close+1,n);
            sub.pop_back();
        }

    }

};

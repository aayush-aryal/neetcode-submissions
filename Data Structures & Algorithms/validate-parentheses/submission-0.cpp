class Solution {
public:
    bool isValid(string s) {

        // stack 
        unordered_map <char,char> brackets={
            {')','('},
            {'}','{'},
            {']','['}
        };
        vector<char> brac_stack;
        int i=0;
        while (i<s.size()){
            // if its an opening bracket push onto the stack
            if (s[i]=='(' || s[i]=='{' || s[i]=='['){
                brac_stack.push_back(s[i]);
            }
            else{
                // if the closing bracket maps to the correct opening bracket
                if (brac_stack.size()>0 and brac_stack.back()== brackets[s[i]]){
                    brac_stack.pop_back();
                }
                else{
                    return false;
                }
            }
            i+=1;
        }
        if (brac_stack.size()==0){
            return true;
        }else{
            return false;
        }
        
    }
};

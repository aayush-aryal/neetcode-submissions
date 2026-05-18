class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set <string> special={"+","-","*","/"};
        stack <int> numStack={};
        int eval=0;
        for (int i=0; i<tokens.size();i++){
            if (!special.contains(tokens[i])){
                // it is a number
                int num= stoi(tokens[i]);
                numStack.push(num);
            }else{
                    int lastNum=numStack.top();
                    numStack.pop();
                    int prev=numStack.top();
                    numStack.pop();
                if (tokens[i]=="+"){
                    eval= lastNum+prev;
                }else if (tokens[i]=="-"){
                    eval=prev-lastNum;
                }else if (tokens[i]=="*"){
                    eval=lastNum*prev;
                }else{
                    eval=prev/lastNum;
                }
                numStack.push(eval);
            }
        } 
        return numStack.top();
        
    }
};

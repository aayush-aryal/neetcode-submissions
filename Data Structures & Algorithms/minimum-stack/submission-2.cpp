class MinStack {
    private:
    vector <int> minStack;
    vector <int> mainStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        // push onto the main stack
        mainStack.push_back(val);
        if ( minStack.empty()|| minStack.back()>=val){
            minStack.push_back(val);
        }  
    }
    
    void pop() {
        int top_val=mainStack.back();
        if (top_val==minStack.back()){
            minStack.pop_back();
        }
        mainStack.pop_back();
        
    }
    
    int top() {
       return mainStack.back();
        
    }
    
    int getMin() {
        return minStack.back();
        
    }
};

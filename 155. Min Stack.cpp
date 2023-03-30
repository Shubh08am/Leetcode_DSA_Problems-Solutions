class MinStack {
public:
//S.C -> O(2N)
//st does stack operation and mini stores minimum element
stack<int>st,mini; // OR USE PRIORITY QUEUE (MIN-HEAP) OR VECTOR OR MULTISET+STACK
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        //only smaller value than mini top inserted in mini
        if(mini.empty() || mini.top()>=val){
            mini.push(val) ;
        }
    }
    
    void pop() {
        //if mini top is equal to st top remove mini top as pop operation 
        if(mini.top()==st.top()) mini.pop();
         st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini.top() ;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

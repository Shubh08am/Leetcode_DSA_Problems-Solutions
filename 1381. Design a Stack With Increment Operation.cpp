class CustomStack {
public:
    //Approach 1:- using an vector as a stack 
    //Approach 2:- use 2 stack
    vector<int>stack;
    int pos=0;
    int maxSize=0;
    CustomStack(int maxSize) {
        this->maxSize=maxSize;
    }
    
    void push(int x) {
        if(pos<maxSize) {stack.push_back(x);pos++;}
    }
    
    int pop() {
        if(stack.size()==0 || pos<0) return -1;
        int ans = stack.back();
        pos--;
        stack.pop_back();
        return ans;
    }
    
    void increment(int k, int val) {
        int m=stack.size();
        int x= min(m,k);
        for(int i=0;i<x;i++) stack[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

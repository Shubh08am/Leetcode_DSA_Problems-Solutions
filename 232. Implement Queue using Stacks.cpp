class MyQueue {
public:
stack<int>first,second;
    MyQueue() {
        
    }
    /*
    push->1
first ->__ -> second se push->1
second - 1 -> pop -> __ 

push->2 
first--> __
second --> 1 
than second --> 1 , 2 
than first--> 2 1 
    */
    void push(int x) {
        while(first.size()!=0){
            int top_of_first = first.top();
            second.push(top_of_first);
            first.pop();
        }
        second.push(x);
         while(second.size()!=0){
            int top_of_second = second.top();
            first.push(top_of_second);
            second.pop();
        }
    }
    
    int pop() {
        int value_popped = first.top();
        first.pop();
        return value_popped ;
    }
    
    int peek() {
        int value_top = first.top();
        return value_top ;
    }
    
    bool empty() {
        return(first.size()==0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

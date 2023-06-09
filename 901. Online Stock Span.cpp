class StockSpanner {
public:
    stack<vector<int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int len=1;
        while(!st.empty() && price>=st.top()[0]){
            len+=st.top()[1];
            st.pop();
       } 
       st.push({price,len});
       cout<<st.top()[0]<<" "<<st.top()[1]<<"\n";
       return len;
    }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

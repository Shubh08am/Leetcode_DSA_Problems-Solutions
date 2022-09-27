class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
          int best_profit =0 ;
     
        // if sorted in ascending order --> best_profit = max_value - min_value      
      if(is_sorted(prices.begin(),prices.end())) {
           best_profit  = prices[n-1]-prices[0];
         }
        
        // if sorted in descending order --> best_profit = 0   
      else if(is_sorted(prices.begin(),prices.end() , greater<int>())) {
 best_profit =0;
      }  
        
        else{
// check (i+1)th element and ith element diff if +ve take it and sell and store it in best_profit 
            for(int i=0;i<n-1;i++){
                int profit = prices[i+1] - prices[i] ;
if( profit >0 ){
    best_profit+=profit;
               }
 }
 }
        return best_profit;
    }
};

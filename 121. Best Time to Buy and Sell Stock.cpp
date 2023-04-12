class Solution {
public:
    //Time Complexity: O(N) && Space Complexity: O(1)
    int maxProfit(vector<int>& prices) {
        //AT ANY INDEX(i) KEEP A TRACK OF MIN VALUE FROM 0 TO (i-1)th POS
        int n = prices.size();
        int minCost = prices[0] ; 
        int profit = 0 ;
        for(int i=1;i<n;i++){ 
          profit = max(profit,prices[i]-minCost); //maximizing the profit
          minCost = min(minCost,prices[i]) ; //keeping track of min value 
        }
        return profit;
    }
};

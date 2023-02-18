class Solution {
public:
 // Recursive Soltion - tle do agian 
    // Time : O(2^N)
    // Space : O(N)
    
    int price(vector<int>& prices, int day, bool buy){
        int n = prices.size();

        if(day >= n){
            return 0;
        }
        
        // First Choice -> No transaction this day
        int choice1 = price(prices, day + 1, buy);
        
        // Second Choice ->  Transaction this day
        int choice2 = 0;
 
        if(buy){
            choice2 =   price(prices, day + 1, false) -prices[day] ;
        }else{
            choice2 =   price(prices, day + 2, true) + prices[day] ;
        }
        
        return max(choice1, choice2);  
    }

    int price2(vector<int>&prices,int i,int buy,vector<vector<int>>&dp){
        if(i>=prices.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int mx=0;
        if(buy==1){
            mx=max(-prices[i]+price2(prices,i+1,0,dp),price2(prices,i+1,1,dp));
        }
        else{
            mx=max(prices[i]+price2(prices,i+2,1,dp),price2(prices,i+1,0,dp));
        }
        return dp[i][buy]=mx;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return price2(prices,0,1,dp);
    }
};

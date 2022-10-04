class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        //  money = money - costi + cashbacki.
        long long int money = 0 ;
        int n = transactions.size();
        
        for(int i=0;i<n;i++){
            //finding max first of cost and cashback
            long long int mn = min(transactions[i][0] , transactions[i][1]);
            money = max(money,mn);   
        }
        
        //see for min amount
         for(int i=0;i<n;i++){
              long long int left = transactions[i][0] - transactions[i][1] ;
              long long int mx = max(0LL,left);
             money= money + mx ;
             
         }
        return money;
    }
};

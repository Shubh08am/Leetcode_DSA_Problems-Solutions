class Solution {
public:
  //APPROACH-1
/*   //memoization approach -> > S.C ->O(N)+O(N) & T.C-> O(N) 
    int solve(vector<int>&dp,int n){
        //base case 
        if(n<=1) return n;
        //checking if sub-problem have been  calculated earlier don't calculate again 
        if(dp[n]!=-1) return dp[n] ; 
        //else solve sub-problem and store it for future 
        return dp[n]=solve(dp,n-1)+solve(dp,n-2);

    }
    int fib(int n) {
        vector<int>dp(n+1,-1); //-1 will denote not calculated yet 
        return solve(dp,n);
    }
    */
   //APPROACH-2
  /*  //Tabulation approach(bottom up) ->> S.C ->O(N) & T.C-> O(N) 
    int fib(int n) {
      vector<int>dp(n+1,-1);
      //from base case assign initial value to dp 
      if(n==0) return 0 ; //as dp[1] will give RTE than
      dp[0]=0;
      dp[1]=1;
      
       //recurrence relation starts from 2 onwards in memoization therefore start from 2 and go till n 
      for(int i=2;i<=n;i++){
          //assign to dp value(of previous 2 values) instead of call 
          dp[i] = dp[i-1] + dp[i-2] ;
      }
       return dp[n];
    */
    //APPROACH-3
    // Space Optimization:- Tabulation approach(bottom up) -> S.C ->O(1) & T.C-> O(N) 
    int fib(int n) {
     int prev2=0,prev=1;
         if(n==0) return 0 ;
       for(int i=2;i<=n;i++){
          //assign to curri value(of previous 2 values) 
          int curri = prev+prev2 ; 
          //update prev2 and prev 
          prev2=prev;
          prev=curri; 
       }
       return prev;
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
         /*
       2 1 1 2 
       take 2 than skip 1 , 1 again take 2 -->  answer -> 4
        */

        int evenPos_Sum=0 , oddPos_Sum=0 , max_sum=0; 
       
        for(int i=0;i<nums.size();i++){
            //if at even index position -> 0,2,4...
            if(!(i&1)){
          evenPos_Sum+=nums[i];
           evenPos_Sum = max(evenPos_Sum,oddPos_Sum);
            }
            //if at odd index position -> 1,3,5...
            if((i&1)){
          oddPos_Sum+=nums[i];
          oddPos_Sum = max(evenPos_Sum,oddPos_Sum);
            }
}
   
        max_sum = max(evenPos_Sum,oddPos_Sum);
        return max_sum;
    }
};

class Solution {
public: 
   //Approach-1 Recursion
  /* int solve(int ind,vector<int>&nums){
       if(ind==0) return nums[0];
       if(ind<0) return 0 ; 
       int pick = nums[ind] + solve(ind-2,nums);
       int notpick = 0+solve(ind-1,nums); 
       return max(pick,notpick);
   }
    int rob(vector<int>& nums) {
       //dp on subsequences 
       int n = nums.size();
       return solve(n-1,nums); 
    }
    */
 /*   //APPROACH-2
    //memoization approach -> S.C ->O(N)+O(N) & T.C-> O(N)
    int solve(int ind,vector<int>&nums,vector<int>&dp){
       if(ind==0) return nums[0];
       if(ind<0) return 0 ; 
       if(dp[ind]!=-1) return dp[ind];
       int pick = nums[ind] + solve(ind-2,nums,dp);
       int notpick = 0+solve(ind-1,nums,dp); 
       return dp[ind]=max(pick,notpick);
   }
    int rob(vector<int>& nums) {
       //dp on subsequences 
       int n = nums.size();
       vector<int>dp(n,-1);
       return solve(n-1,nums,dp); 
    */
 
  /*  //APPROACH-3
    //Tabulation approach(bottom up) -> S.C ->O(N) & T.C-> O(N) 
      int rob(vector<int>& nums) {
       //dp on subsequences 
       int n = nums.size();
       vector<int>dp(n,-1);
       dp[0]=nums[0]; //from base case 
       for(int i=1;i<n;i++){
           int pick = nums[i] ; 
           if(i>1) pick+=dp[i-2] ;  //from recurrence relation
           int notpick = 0+dp[i-1] ;
           dp[i] = max(pick,notpick);
       }
       return dp[n-1];
       */
   //APPROACH-4
    //Tabulation approach(bottom up) -> S.C ->O(1) & T.C-> O(N) 
     int rob(vector<int>& nums) {
        int n = nums.size();
       int prev=nums[0] , prev2=0; //from base case 
        for(int i=1;i<n;i++){
           int pick = nums[i] ; 
           if(i>1) pick+=prev2 ;  //from recurrence relation
           int notpick = 0+prev;
           int curri = max(pick,notpick);
           prev2=prev;
           prev=curri;
       }
       return prev;
   }
};

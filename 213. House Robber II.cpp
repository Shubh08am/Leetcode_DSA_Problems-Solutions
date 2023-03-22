class Solution {
public:
  /* //Approach-1 Recursion
    int solve(int index,vector<int>&nums){
        //base case 
        if(index==0) return nums[index] ; //as we didn't pick 1 we pick 0 
        if(index<0) return 0 ; 

        int pick = nums[index]  ; //pick therefore sum increases by nums[i] 
        //and call recursively for index-2 position as index-1 is not allowed to pick 
         if(index>1) pick+=solve(index-2,nums);
        int notpick = 0+solve(index-1,nums);  //notpicked therefore sum didn't increase but we can pick index-1 now
        return max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        //dp on subsequences 
        int n = nums.size();
        if(n==1) return nums[0];
        int start=nums[0],end=nums[n-1];
        //2 times call 
        //once, ignoring last element(n-1th)
        nums.pop_back();
        int ans1 = solve(n-2,nums);

        //second, ignoring start element(0th)
        nums.push_back(end);
        nums.erase(nums.begin());
        int ans2 = solve(n-2,nums);

        return max(ans1,ans2);//return max 
    }*/
 /*   //APPROACH-2
    //memoization approach -> S.C ->O(N)+O(N)(+more) & T.C-> O(N) 
    int solve(int index,vector<int>&nums,vector<int>&dp){
        //base case 
        if(index==0) return nums[index] ; //as we didn't pick 1 we pick 0 
        if(index<0) return 0 ; 
        
        //check if sub-problems already solved
        if(dp[index]!=-1) return dp[index] ;

        int pick = nums[index]  ; //pick therefore sum increases by nums[i] 
        //and call recursively for index-2 position as index-1 is not allowed to pick 
         if(index>1) pick+=solve(index-2,nums,dp);
         
        int notpick = 0+solve(index-1,nums,dp);  //notpicked therefore sum didn't increase but we can pick index-1 now

        return dp[index]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        //dp on subsequences 
       
        int n = nums.size();
        vector<int>dp(n-1,-1),dp2(n-1,-1); //use 2 dp array or reassign to one after use
        if(n==1) return nums[0];
        int start=nums[0],end=nums[n-1];
        //2 times call 
        //once, ignoring last element(n-1th)
        nums.pop_back();
        int ans1 = solve(n-2,nums,dp);
          for(int i=0;i<n-1;i++) dp[i]=-1;//re-assign 
         //second, ignoring start element(0th)
        nums.push_back(end);
        nums.erase(nums.begin());
        
        int ans2 = solve(n-2,nums,dp);

        return max(ans1,ans2);//return max 
*/
 /*     //APPROACH-3
    //Tabulation approach(bottom up) -> S.C ->O(4N) & T.C-> O(N) 
    int tabulation(vector<int>& nums,vector<int>&dp){
          int n = nums.size();//here n already n-1 of original size
          for(int i=1;i<n;i++){
            int pick = nums[i] ; 
            if(i>1) pick+=dp[i-2] ; 
            int notpick = 0+dp[i-1] ; 
            //take max one of both in dp 
            dp[i]=max(pick,notpick);
        }
        return dp[n-1] ;
       }
        int rob(vector<int>& nums) {
        //dp on subsequences 
        int n = nums.size();
        vector<int>dp(n,-1),dp2(n,-1); //use 2 dp array or reassign to one after use
        if(n==1) return nums[0];
        //from base case
        dp[0]=nums[0]; 
        dp2[0]=nums[1]; //as 0th index not picked take first
        vector<int>temp1(nums.begin(),nums.end()-1);//won't consider last element in this
        vector<int>temp2(nums.begin()+1,nums.end());//won't consider first element in this
        int ans1 = tabulation(temp1,dp) ;
        int ans2 = tabulation(temp2,dp2) ;
        return max(ans1,ans2);//return max 
*/
//APPROACH-4
    //Tabulation approach(bottom up) -> S.C ->O(1)(if not taking in count vector space used) & T.C-> O(N) 
    int tabulationSpaceOp(vector<int>&nums){
        int prev = nums[0] , prev2=0;
        int n = nums.size();
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1) pick+=prev2;
            int notpick=0+prev;
            int curri=max(pick,notpick);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
         int n = nums.size();
        if(n==1) return nums[0];
        vector<int>temp1(nums.begin(),nums.end()-1);//won't consider last element in this
        vector<int>temp2(nums.begin()+1,nums.end());//won't consider first element in this
        int ans1 = tabulationSpaceOp(temp1) ;
        int ans2 = tabulationSpaceOp(temp2) ;
        return max(ans1,ans2);//return max 
    }
};

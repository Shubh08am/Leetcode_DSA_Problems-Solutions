class Solution {
public:
    //Approach-1 Recursion (from 0 call)
    int solve(int ind,int target,vector<int>& nums){
        int n = nums.size();
        if(ind==n-1){
                //NOTE:- nums[n-1] can be 0 
                if(nums[n-1]==0 && target==0){ //both pick & not pick case
                    return 2;
                }
                if(target==0) return 1; //not-pick case
                if(nums[n-1]==target) return 1; //-pick case
                return 0;
        }

        int notTake=solve(ind+1,target,nums);
        int take = 0;
        //if possible to take 
        if(nums[ind]<=target){
            take=solve(ind+1,target-nums[ind],nums);
        }
        return take+notTake;
    }
    //Approach-1 Recursion (from n-1 call)
 int solve3(int ind,int tar,vector<int> &nums){
     int n = nums.size();
     if(ind==0){
        if(nums[0]==0 && tar==0) return 2;
         if(nums[0]==tar || tar==0) return 1;
         return 0;
    }
    int take = 0 ; 
    if(nums[ind]<=tar) take=solve3(ind-1,tar-nums[ind],nums) ; 
    int notTake = solve3(ind-1,tar,nums) ;  
    return take+notTake;
}

//Approach-2 Memoization Time Complexity: O(N*tar) , Space Complexity:O(N*tar)+ O(N)
 //(from 0 call)
 int solve2(int ind,int tar,vector<int> &nums,vector<vector<int>>&dp){
     int n = nums.size();
      if(ind==n-1){
        if(nums[n-1]==0 && tar==0) return 2;
         if(nums[n-1]==tar || tar==0) return 1;
         return 0;
    }
    if(dp[ind][tar+1000]!=-1) return dp[ind][tar+1000] ;
    int take = 0 ; 
    if(nums[ind]<=tar) take=solve2(ind+1,tar-nums[ind],nums,dp) ; 
    int notTake = solve2(ind+1,tar,nums,dp) ;  
    return dp[ind][tar+1000] =  take+notTake;
}
//Approach-2 Memoization (from n-1 call)
 int solve4(int ind,int tar,vector<int> &nums,vector<vector<int>>&dp){
     int n = nums.size();
     if(ind==0){
        if(nums[0]==0 && tar==0) return 2; //both pick & notpick cases
         if(nums[0]==tar || tar==0) return 1; //nums[0]==tar -> pick case && tar==0 -> notpick case
         return 0;
    }
    if(dp[ind][tar+1000]!=-1) return dp[ind][tar+1000] ;
    int take = 0 ; 
    if(nums[ind]<=tar) take=solve4(ind-1,tar-nums[ind],nums,dp) ; 
    int notTake = solve4(ind-1,tar,nums,dp) ;  
    return dp[ind][tar+1000] = take+notTake;
}

//Approach-3 Tabulation Time Complexity:  O(N*tar) , Space Complexity:O(N*tar)
 //(from 0 call)
int tabulation(vector<int> &num, int tar){
    int n = num.size();
    vector<vector<int>>dp(n,vector<int>(2001,0));
     
    //call from (0,tar) && base case when i=n-1 
    //Thus,bottom up -> from base case to up i.e n-1 to 0 

    //for ind=n-1 
   // if((num[n-1]==0 && tar==0) || (num[n-1]==0 && tar!=0 )) dp[n-1][0] = 2 ; //both pick & notpick cases
    if(num[n-1]==0) dp[n-1][0] = 2 ; //both pick & notpick cases
   // else if( (num[n-1]!=0 && tar==0) || (num[n-1]!=0 && tar!=0 )  )dp[n-1][0] = 1 ; //notpick case
 //or write this 
 else dp[n-1][0] = 1 ; //notpick case
    if(num[n-1]!=0 && num[n-1]<=tar) dp[n-1][num[n-1]] = 1 ; //pick case 

    //for ind=n-2 onwards 
    for(int ind=n-2;ind>=0;ind--){
        for(int target=0;target<=abs(tar);target++){
            int notTake = dp[ind+1][target];
            int take=0;
            if(num[ind]<=target) take=dp[ind+1][target-num[ind]];

            dp[ind][target] = (take+notTake);
        }
    }
    return dp[0][tar];
}

//Approach-3 Tabulation Time Complexity:  O(N*tar) , Space Complexity:O(N*tar)
 //(from n-1 call)
int tabulation2(vector<int> &num, int tar){
    int n = num.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,0));
     
    //call from (0,tar) && base case when i=n-1 
    //Thus,bottom up -> from base case to up i.e n-1 to 0 

    //for ind=0
   // if((num[0]==0 && tar==0) || (num[0]==0 && tar!=0 )) dp[0][0] = 2 ; //both pick & notpick cases
     if(num[0]==0) dp[0][0] = 2 ; //both pick & notpick cases
  //  if(num[0]!=0 && tar!=0) dp[0][0] = 1 ; //notpick case
      else dp[0][0] = 1; 
    if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1 ; //pick case 

    //for ind=1 onwards 
    for(int ind=1;ind<n;ind++){
        for(int target=0;target<=tar;target++){
            int notTake = dp[ind-1][target];
            int take=0;
            if(num[ind]<=target) take=dp[ind-1][target-num[ind]];

            dp[ind][target] = (take+notTake);
        }
    }
    return dp[n-1][tar];
}

//Approach-4 Tabulation with Space Optimization Time Complexity:  O(N*tar) , Space Complexity:O(tar)
 //(from 0 call)
int tabulationSpaceOptimization(vector<int> &num, int tar){
    int n = num.size();
    vector<int>prev(tar+1,0),curr(tar+1,0);
     
    //call from (0,tar) && base case when i=n-1 
    //Thus,bottom up -> from base case to up i.e n-1 to 0 

    //for ind=n-1 
    if((num[n-1]==0 && tar==0) || (num[n-1]==0 && tar!=0 )) prev[0] = 2 ; //both pick & notpick cases
    //  if(num[n-1]==0) prev[0] = 2 ; //both pick & notpick cases
     // else if( (num[n-1]!=0 && tar==0) || (num[n-1]!=0 && tar!=0 )  ) prev[0] = 1 ; //notpick case
      //or write this
      else prev[0]=1;
    if(num[n-1]!=0 && num[n-1]<=tar) prev[num[n-1]] = 1 ; //pick case 

    //for ind=n-2 onwards 
    for(int ind=n-2;ind>=0;ind--){
        for(int target=0;target<=tar;target++){
            int notTake = prev[target];
            int take=0;
            if(num[ind]<=target) take=prev[target-num[ind]];

            curr[target] = (take+notTake);
        }
        prev=curr;
    }
    return prev[tar];
}

//Approach-4 Tabulation Time Complexity:  O(N*tar) , Space Complexity:O(N*tar)
 //(from n-1 call)
int tabulationSpaceOptimization2(vector<int> &num, int tar){
    int n = num.size();
    vector<int>prev(tar+1,0),curr(tar+1,0);
     
    //call from (0,tar) && base case when i=n-1 
    //Thus,bottom up -> from base case to up i.e n-1 to 0 

    //for ind=0
   // if((num[0]==0 && tar==0) || (num[0]==0 && tar!=0 )) dp[0][0] = 2 ; //both pick & notpick cases
     if(num[0]==0) prev[0] = 2 ; //both pick & notpick cases
    if(num[0]!=0 && tar!=0 || num[0]!=0 && tar==0 ) prev[0] = 1 ; //notpick case
    //  else prev[0] = 1; //or use this
    if(num[0]!=0 && num[0]<=tar) prev[num[0]] = 1 ; //pick case 

    //for ind=1 onwards 
    for(int ind=1;ind<n;ind++){
        for(int target=0;target<=tar;target++){
            int notTake = prev[target];
            int take=0;
            if(num[ind]<=target) take=prev[target-num[ind]];

            curr[target] = (take+notTake);
        }
        prev=curr;
    }
    return prev[tar];
}

    int findTargetSumWays(vector<int>& nums, int target) { 
        //COUNT PARTITION WITH GIVEN DIFFERENCE
        //s1-s2 = target where s1 sum of all +ve elements & s2 sum of all -ve elements 
        //Now, s1+s2 = totalSum --> s2 = (totalSum-target)/2 

        //edge cases :- If (totalSum-target) becomes -ve or(totalSum-target) is odd than notPossible 

        int totalSum=0 , n = nums.size();
        for(auto&val:nums) totalSum+=val;
        int diff = (totalSum-target) ;
        if(diff<0 || diff&1) return 0;
        
        //return solve(0,diff/2,nums); //Approach-1 Recursion
        //return solve3(n-1,diff/2,nums); //Approach-1 Recursion

      // vector<vector<int>>dp(n,vector<int>(2001,-1)); //to avoid negative target creating large size array
     //  return solve2(0,diff/2,nums,dp); //Approach-2 Memoization
  //  return solve4(n-1,diff/2,nums,dp); //Approach-2 Memoization

     //return tabulation(nums,diff/2) ; //Approach-3 Tabulation
    //  return tabulation2(nums,diff/2) ; 
   // return tabulationSpaceOptimization(nums,diff/2) ; //Approach-4 Tabulation With S.O
    return tabulationSpaceOptimization2(nums,diff/2) ; //Approach-4 Tabulation With S.O
    }
};

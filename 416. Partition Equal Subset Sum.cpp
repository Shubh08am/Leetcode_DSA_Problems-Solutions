class Solution {
public:
    //Approach-1 Using 2d dp [Memoization]
        int solve(int ind,int firstSum ,int totalSum ,vector<int>& nums,vector<vector<int>>&dp){
            int n = nums.size();
                if(ind==n-1){
                    if(firstSum==totalSum) return 1;
                    else return 0;
                }
        if(dp[ind][firstSum]!=-1) return dp[ind][firstSum] ;
        int pick = 0 , notPick=0;
        pick = solve(ind+1,firstSum+nums[ind],totalSum-nums[ind],nums,dp) ; 
        notPick = solve(ind+1,firstSum,totalSum,nums,dp) ; 
        return dp[ind][firstSum] = pick || notPick ;
        }
    //Approach-2 Using 3d dp -> Gives TLE OR MLE
        int solve2(int ind,int firstSum ,int totalSum ,vector<int>& nums, vector<vector<vector<int>>>&dp3){
            int n = nums.size();
                if(ind==n-1){
                    if(firstSum==totalSum) return 1;
                    else return 0;
                }
        if(dp3[ind][totalSum][firstSum]!=-1) return dp3[ind][totalSum][firstSum] ;
        int pick = 0 , notPick=0;
        pick = solve2(ind+1,firstSum+nums[ind],totalSum-nums[ind],nums,dp3) ; 
        notPick = solve2(ind+1,firstSum,totalSum,nums,dp3) ; 
        return dp3[ind][totalSum][firstSum] = pick || notPick ;
        }
        
    //Approach-3 Memoization :- T.C = O(N*TARGET)+O(N)[for totalsum] S.C=O(N*TARGET) + O(N)
int solve(int ind,vector<int>&arr,vector<vector<int>>&dp, int sum){
    int n = arr.size();
    if(sum==0) return 1;
     if(ind==n-1) return arr[n-1]==sum;
    if(dp[ind][sum]!=-1) return dp[ind][sum];
    int pick=0;
    if(arr[ind]<=sum)  pick =  solve(ind+1,arr,dp,sum-arr[ind]);
    int notPick = solve(ind+1,arr,dp,sum);

    return dp[ind][sum]=notPick||pick ;
}
//Approach-4 Tabulation T.C = O(N*TARGET)+O(N)[for totalsum] S.C=O(N*TARGET)
int tabulation(vector<int>&arr, int sum,vector<vector<bool>>&dp){
     int n = arr.size();
    //base case when sum=0 ind varies from 1 to n , for target=0
    for(int i=0;i<n;i++) dp[i][0] = true; 
    //when at last pos only for that target true , for i=n-1
    if(arr[n-1]<=sum) dp[n-1][arr[n-1]] = true; 
    
    //for ind = n-1 done see from ind=n-2 onwards and target=1 onwards as for target=0 all true done
    for(int ind=n-2;ind>=0;ind--){
        for(int target=1;target<=sum;target++){
            bool notPick = dp[ind+1][target] ; 
            bool pick=false;
            if(arr[ind]<=target)  pick =  dp[ind+1][target-arr[ind]]; 
            dp[ind][target]=notPick|pick ;
        }
    }
    return dp[0][sum] ;
} 
//Approach-5 Tabulation with Space Optimization Time Complexity: O(N*target)+O(N)[for totalsum] , Space Complexity:O(target)
int tabulationSpaceOptimization(vector<int>&arr, int sum){
     int n = arr.size();
     vector<int>prev(sum+1,0) , curr(sum+1,0);
      prev[0] = curr[0] = true; 
    //when at last pos only for that target true , for i=n-1
    if(arr[n-1]<=sum) prev[arr[n-1]] = true; 
    
    //for ind = n-1 done see from ind=n-2 onwards and target=1 onwards as for target=0 all true done
    for(int ind=n-2;ind>=0;ind--){
        for(int target=1;target<=sum;target++){
            bool notPick = prev[target] ; 
            bool pick=false;
            if(arr[ind]<=target)  pick =  prev[target-arr[ind]]; 
            curr[target]=notPick|pick ;
        }
        prev=curr;
    }
    return prev[sum] ;
}
    bool canPartition(vector<int>& nums) {
        int totalSum = 0 , n = nums.size(); 
        for(auto&val:nums) totalSum+=val;
    //    vector<vector<int>>dp(n,vector<int>(totalSum+1,-1));
    //    return solve(0,0,totalSum,nums,dp) ; //Approach-1 Using 2d dp

    //  vector<vector<vector<int>>>dp3(n,vector<vector<int>>(totalSum+1,vector<int>(totalSum+1,-1))) ;
    //    return solve2(0,0,totalSum,nums,dp3) ; //Approach-2 Using 3d dp
        
        int sum=totalSum/2; //Subset Sum Equal To K(k=totalSum/2)
        if(totalSum&1) return false; //if odd not possible

     //   vector<vector<int>>dp(n,vector<int>(sum+1,-1)) ; 
     //   return solve(0,nums,dp,sum); //Approach-3
     
    //  vector<vector<bool>>dp(n,vector<bool>(sum+1,false)) ; //Approach-tabulation 
    //   return tabulation(nums,sum,dp); //Approach-4
      
      return tabulationSpaceOptimization(nums,sum); //Approach-5 tabulationSpaceOptimization
    }
};

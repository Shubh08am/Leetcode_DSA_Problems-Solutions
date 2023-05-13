class Solution {
public:
     //Approach-1 Recursion Time Complexity: O(2^N) Space Complexity: O(N)
    int solve(int ind,int prev_ind,vector<int>&nums){
        int n=nums.size();
        if(ind==n) return 0;

        int notTake=0+solve(ind+1,prev_ind,nums); 
        int take = 0 ; 

        if(prev_ind==-1 || (nums [ind]>nums[prev_ind] && ind-prev_ind==1)){
            take=1+solve(ind+1,ind,nums);
        }

        return max(take,notTake);
    }
    //Approach-2 Memoization :- Time Complexity: O(N*N) Space Complexity: O(N*N) + O(N)
    //Recursion call from (0,-1)
     int solve2(int ind,int prev_ind,vector<int>&nums,vector<vector<int>>&dp){
        int n=nums.size();
        if(ind==n) return 0;
        
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];

        int notTake=0+solve2(ind+1,prev_ind,nums,dp); 
        int take = 0 ; 

        if(prev_ind==-1 || (nums [ind]>nums[prev_ind] && ind-prev_ind==1)){
            take=1+solve2(ind+1,ind,nums,dp);
        }

        return dp[ind][prev_ind+1]= max(take,notTake);
    }
    //Approach-3 Tabulation :- Time Complexity: O(N*N) Space Complexity: O(N*N)
    //Recursion call from (0,-1)
    int tabulation(vector<int>&nums){
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int ind=n-1;ind>=0;ind--){
            for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
                int notTake=0+dp[ind+1][prev_ind+1] ; //prev_ind+1 as right shifting[co-ordinate shift] of prev_ind
               int take=0;

               if(prev_ind==-1 || (nums[ind]>nums[prev_ind] && ind-prev_ind==1)){
                   take=1+dp[ind+1][ind+1]; //as taking prev_ind becomes ind and shifting -> ind+1 
               }
               dp[ind][prev_ind+1]=max(take,notTake);
           }
       }
       return dp[0][0]; //as recursion call from (0,-1) and prev_ind right shifted -> -1+1=0
    }
        //Approach-4 Sliding Window :- Time Complexity: O(N) Space Complexity: O(1)
     int SlidingWindow(vector<int>&nums){
       int n=nums.size();
        int i=0,j=1,ans=1,curr=1;
        while(j<n){
            if(i<n && nums[i]<nums[j]){
                i++;
                j++;
                curr++;
            }
            else{
                curr=1;
                i=j;
                j++;
            }
            ans=max(ans,curr);
        }
        return ans;
    }
    int findLengthOfLCIS(vector<int>& nums) {
     //   return solve(0,-1,nums); //Approach-1 Recursion  
          int n=nums.size();
     //     vector<vector<int>>dp(n,vector<int>(n+1,-1));//co-ordinate shift done[Right Shifting of index] as prev=-1 can't be represented 
    //     return solve2(0,-1,nums,dp); //Approach-2 Memoization

   //         return tabulation(nums) ; //Approach-3 Tabulation 
            return SlidingWindow(nums);  //Approach-4 SlidingWindow
        
    }
};

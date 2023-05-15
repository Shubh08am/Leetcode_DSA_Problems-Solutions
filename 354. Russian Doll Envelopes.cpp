class Solution {
public:
    //Approach-1 Recursion Time Complexity: O(2^N) Space Complexity: O(N)
    int solve(int ind,int prevInd,vector<vector<int>>& envelopes){
        int n=envelopes.size();
        if(ind==n) return 0;

        //take notTake now 
        int take = 0;
        //take when first element for which prevInd is -1 
        //or when next element is greater than previous one 

        if(prevInd==-1 || envelopes[ind][0]>envelopes[prevInd][0] && envelopes[ind][1]>envelopes[prevInd][1]){
         //prevInd is updated to ind position now
            take = 1+solve(ind+1,ind,envelopes);
        }
        int notTake = 0+solve(ind+1,prevInd,envelopes);

        return max(take,notTake);
    }   
     //Approach-2 Memoization :- Time Complexity: O(N*N) Space Complexity: O(N*N) + O(N)
    //Recursion call from (0,-1)
        int solve2(int ind,int prevInd,vector<vector<int>>& envelopes,vector<vector<int>>&dp){
        int n=envelopes.size();
        if(ind==n) return 0;

        if(dp[ind][prevInd+1]!=-1) return dp[ind][prevInd+1];
        
        //take notTake now 
        int take = 0;
        //take when first element for which prevInd is -1 
        //or when next element is greater than previous one 

        if(prevInd==-1 ||  envelopes[ind][0]>envelopes[prevInd][0] && envelopes[ind][1]>envelopes[prevInd][1]){
         //prevInd is updated to ind position now
            take = 1+solve2(ind+1,ind,envelopes,dp);
        }
        int notTake = 0+solve2(ind+1,prevInd,envelopes,dp);

        return dp[ind][prevInd+1] = max(take,notTake);
    }
    //Approach-3 Tabulation :- Time Complexity: O(N*N) Space Complexity: O(N*N)
    //Recursion call from (0,-1)
    int tabulation(vector<int>&nums){
        //tabulation from ind=n -> 0 and prev=ind-1 -> -1 
         int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        //for base case when ind==n return 0 -> prev_ind varies from 0 to n
        for(int prev_ind=0;prev_ind<=n;prev_ind++) dp[n][prev_ind]=0;

       //for ind=n-1 onwards and prev_ind=ind-1 onwards 

       for(int ind=n-1;ind>=0;ind--){
           for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
               //co-ordinate shift to represent prev_ind=-1 need to be done 
               int notTake=0+dp[ind+1][prev_ind+1] ; //prev_ind+1 as right shifting[co-ordinate shift] of prev_ind
               int take=0;

               if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
                   take=1+dp[ind+1][ind+1]; //as taking prev_ind becomes ind and shifting -> ind+1 
               }

               dp[ind][prev_ind+1]=max(take,notTake);
           }
       }
       return dp[0][0]; //as recursion call from (0,-1) and prev_ind right shifted -> -1+1=0
    }
    //Approach-3 Tabulation :- Time Complexity: O(N*N) Space Complexity: O(N*N)
    //Recursion call from (0,-1)
    int tabulation(vector<vector<int>>& envelopes){
        //tabulation from ind=n -> 0 and prev=ind-1 -> -1 
         int n=envelopes.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        //for base case when ind==n return 0 -> prev_ind varies from 0 to n
        for(int prev_ind=0;prev_ind<=n;prev_ind++) dp[n][prev_ind]=0;

       //for ind=n-1 onwards and prev_ind=ind-1 onwards 

       for(int ind=n-1;ind>=0;ind--){
           for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
               //co-ordinate shift to represent prev_ind=-1 need to be done 
               int notTake=0+dp[ind+1][prev_ind+1] ; //prev_ind+1 as right shifting[co-ordinate shift] of prev_ind
               int take=0;

               if(prev_ind==-1 || envelopes[ind][0]>envelopes[prev_ind][0] && envelopes[ind][1]>envelopes[prev_ind][1]){
                   take=1+dp[ind+1][ind+1]; //as taking prev_ind becomes ind and shifting -> ind+1 
               }

               dp[ind][prev_ind+1]=max(take,notTake);
           }
       }
       return dp[0][0]; //as recursion call from (0,-1) and prev_ind right shifted -> -1+1=0
    }
    int lowerBound(vector<int>& nums,int key){
        int n=nums.size(); 
        int start=0,end=n-1;

        while(start<end){
            int mid=start+(end-start)/2; 

            if(nums[mid]>=key){
                end=mid;
             }
            else if(nums[mid]<key){
                start=mid+1;
            }
        }
        if(start<n && nums[start]<key) start++;
        
        return start;
    }
    //Approach-4 Binary Search    
   //Time Complexity: O(N*LOGN) : We iterate over the array of size N and in every iteration, we perform a binary search which takes logN time.
   //Space Complexity: O(N) : We are using an extra array of size N to store the temp variable.
    int binarySearch(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        vector<int>lis; 
        //Using width now 
        lis.push_back(envelopes[0][1]);

        for(int i=1;i<n;i++){
            if(envelopes[i][1]>lis.back()) lis.push_back(envelopes[i][1]);
            else{
             //   int pos = lower_bound(lis.begin(),lis.end(),envelopes[i][1])-lis.begin();
                   int pos = lowerBound(lis,envelopes[i][1]);
                   lis[pos] = envelopes[i][1];
            }
        }
    return lis.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        // SORT ON THE BASIS OF HEIGHT(SMALLER HEIGHT FIRST) -> IF SAME HEIGHT ON BASIS OF WIDTH (LARGER WIDTH FIRST)
        sort(envelopes.begin(),envelopes.end(),[&](auto&a,auto&b){return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];});
      
       // return solve(0,-1,envelopes); //Approach-1 Recursion

//  vector<vector<int>>dp(n,vector<int>(n+1,-1));//co-ordinate shift done[Right Shifting of index] as prev=-1 can't be represented 
     //  return solve2(0,-1,envelopes,dp); //Approach-2 Memoization 
        
     //    return tabulation(envelopes); //Approach-3 tabulation 

         return binarySearch(envelopes); //Approach-4 Binary Search 
    }
};

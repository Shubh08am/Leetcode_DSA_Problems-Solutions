class Solution {
public:
   //Approach-1 Recursion Time Complexity: O(2^N) Space Complexity: O(N)
    int solve(int ind,int prevInd,vector<int>&nums){
        int n=nums.size();
        if(ind==n) return 0;

        //take notTake now 
        int take = 0;
        //take when first element for which prevInd is -1 
        //or when next element is greater than previous one 

        if(prevInd==-1 || nums[ind]>nums[prevInd]){
         //prevInd is updated to ind position now
            take = 1+solve(ind+1,ind,nums);
        }
        int notTake = 0+solve(ind+1,prevInd,nums);

        return max(take,notTake);
    }   
    //Approach-2 Memoization :- Time Complexity: O(N*N) Space Complexity: O(N*N) + O(N)
    //Recursion call from (0,-1)
         int solve2(int ind,int prevInd,vector<int>&nums,vector<vector<int>>&dp){
        int n=nums.size();
        if(ind==n) return 0;

        if(dp[ind][prevInd+1]!=-1) return dp[ind][prevInd+1];
        
        //take notTake now 
        int take = 0;
        //take when first element for which prevInd is -1 
        //or when next element is greater than previous one 

        if(prevInd==-1 || nums[ind]>nums[prevInd]){
         //prevInd is updated to ind position now
            take = 1+solve2(ind+1,ind,nums,dp);
        }
        int notTake = 0+solve2(ind+1,prevInd,nums,dp);

        return dp[ind][prevInd+1] = max(take,notTake);
    }
    
     //Approach-2 Memoization :- Time Complexity: O(N*N) Space Complexity: O(N*N) + O(N)
    //Recursion call from (n,n+1) i.e from back 
         int solve3(int ind,int nextInd,vector<int>&nums,vector<vector<int>>&dp){
        int n=nums.size();
        if(ind==0) return 0;

        if(dp[ind][nextInd]!=-1) return dp[ind][nextInd];
        
        //take notTake now 
        int take = 0;
        //take when first element for which prevInd is -1 
        //or when next element is greater than previous one 

        if(nextInd==n+1 || nums[ind-1]<nums[nextInd-1]){
         //prevInd is updated to ind position now
            take = 1+solve3(ind-1,ind,nums,dp);
        }
        int notTake = 0+solve3(ind-1,nextInd,nums,dp);

        return dp[ind][nextInd] = max(take,notTake);
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
    //Recursion call from (n,n+1)
    int tabulation2(vector<int>&nums){
        //tabulation from ind= 0 -> n and next_ind = ind+1 -> n+1
         int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+2,0));

        //for base case when ind==0 return 0 -> next_ind varies from 0 to n+1
        for(int next_ind=0;next_ind<=n+1;next_ind++) dp[0][next_ind]=0;

       //for ind=1 onwards and next_ind=ind+1 onwards 

       for(int ind=1;ind<=n;ind++){
           for(int next_ind=ind+1;next_ind<=n+1;next_ind++){
                int notTake=0+dp[ind-1][next_ind] ;  
               int take=0;

               if(next_ind==n+1 || nums[ind-1]<nums[next_ind-1]){
                   take=1+dp[ind-1][ind]; //as taking next_ind becomes ind 
               }

               dp[ind][next_ind]=max(take,notTake);
           }
       }
       return dp[n][n+1]; //as recursion call from (0,-1) and prev_ind right shifted -> -1+1=0
    }

     //Approach-4 tabulation With Space Optimization :- Time Complexity: O(N*N) Space Complexity: O(N)
    //Recursion call from (0,-1)  
    int tabulationWithSpaceOptimization(vector<int>& nums){
            int n=nums.size();
            vector<int>next(n+1,0),curr(n+1,0);

       //for ind=n-1 onwards and prev_ind=ind-1 onwards 
       //dp[ind+1] -> next 
       //dp[ind] -> curr
       for(int ind=n-1;ind>=0;ind--){
           for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
               //co-ordinate shift to represent prev_ind=-1 need to be done 
               int notTake=0+next[prev_ind+1] ; //prev_ind+1 as right shifting[co-ordinate shift] of prev_ind
               int take=0;

               if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
                   take=1+next[ind+1]; //as taking prev_ind becomes ind and shifting -> ind+1 
               }

               curr[prev_ind+1]=max(take,notTake);
           }
           next=curr;//update
       }
       return next[0]; //curr[0] also works as next=curr this time
    }
     //Approach-5 tabulation With Space Optimization[Using one array] :- Time Complexity: O(N*N) Space Complexity: O(N)
    //Recursion call from (0,-1)  
    int tabulationWithSpaceOptimization3(vector<int>& nums){
            int n=nums.size();
            vector<int>next(n+1,0);
       //for ind=n-1 onwards and prev_ind=ind-1 onwards 
       //dp[ind+1] -> next 
       for(int ind=n-1;ind>=0;ind--){
           for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
               //co-ordinate shift to represent prev_ind=-1 need to be done 
               int notTake=0+next[prev_ind+1] ; //prev_ind+1 as right shifting[co-ordinate shift] of prev_ind
               int take=0;

               if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
                   take=1+next[ind+1]; //as taking prev_ind becomes ind and shifting -> ind+1 
               }
               next[prev_ind+1]=max(take,notTake);
           }
        }
       return next[0];
    }

     //Approach-4 tabulation With Space Optimization :- Time Complexity: O(N*N) Space Complexity: O(N)
    //Recursion call from (n,n+1)  
    int tabulationWithSpaceOptimization2(vector<int>& nums){
            int n=nums.size();
            vector<int>prev(n+2,0),curr(n+2,0);

            for(int ind=1;ind<=n;ind++){
                    for(int next_ind=ind+1;next_ind<=n+1;next_ind++){
                        int notTake=0+prev[next_ind];
                        int take=0;
                        if(next_ind==n+1||nums[ind-1]<nums[next_ind-1]){
                            take=1+prev[ind];
                        }
                        curr[next_ind]=max(take,notTake);
                    }
                    prev=curr;//update
            }
        return prev[n+1];
    }
    //Approach-5 tabulation With Space Optimization :- Time Complexity: O(N*N) Space Complexity: O(N)
    //Recursion call from (n,n+1)  
    int tabulationWithSpaceOptimization4(vector<int>& nums){
            int n=nums.size();
            vector<int>prev(n+2,0);

            for(int ind=1;ind<=n;ind++){
                    for(int next_ind=ind+1;next_ind<=n+1;next_ind++){
                        int notTake=0+prev[next_ind];
                        int take=0;
                        if(next_ind==n+1||nums[ind-1]<nums[next_ind-1]){
                            take=1+prev[ind];
                        }
                        prev[next_ind]=max(take,notTake);
                    }
            }
        return prev[n+1];
    }

    //Approach-6 Tabulation algorithm to find the length of the longest increasing subsequence. 
    //Time Complexity: O(N*N) Space Complexity: O(N)
    int TabulationAlgorithm(vector<int>& nums){
        int n=nums.size();
        //LOGIC:- CAN THAT ELEMENT[FROM PREV_INDEX] BE A PART OF SUB-SEQUENCE THAT ENDS AT [IND] 
        // IF YES, INCREASE THE LENGTH OF LIS BY 1 AS WE INCLUDE NUMS[PREV_INDEX] IN SUBSEQUENCE
        //CHECK BY COMPARING NUMS[PREV_INDEX] < NUMS[IND] 
        //AT,LAST GIVE MAX ELEMENT FROM DP 
        vector<int>dp(n+1,1); // Length of lis can always be 1 include single elements only therefore initialized to 1 
        int lis=1;
        for(int ind=0;ind<n;ind++){
            for(int prev_ind=0;prev_ind<ind;prev_ind++){
                if(nums[ind]>nums[prev_ind]){
                    dp[ind]=max(dp[ind],1+dp[prev_ind]);
                }
            }
            lis=max(lis,dp[ind]);
        }
        return lis;
    }
    //Printing the LIS :- Time Complexity: O(N*N)+O(LENGTH OF LIS) [FOR BACTRACKING] Space Complexity: O(N)
    void printLIS(int n,vector<int>&nums){
        vector<int>dp(n,1) , hash(n) ; 
        //dp gives length of LIS 
        //hash is used to backtrack and print LIS by storing prev index of elements

    for(int ind=0;ind<n;ind++){
        hash[ind]=ind;
        for(int prev_ind=0;prev_ind<ind;prev_ind++){
            if(nums[ind]>nums[prev_ind] && dp[ind]<1+dp[prev_ind]){
                    dp[ind]=1+dp[prev_ind];
                    hash[ind]=prev_ind;
            }
        }
    }

    int lenOfLIS = 1 , lastIndex=0; //store the index of last element of lis and start from it  
    for(int i=0;i<n;i++){
        if(lenOfLIS<dp[i]){
            lenOfLIS=dp[i];
            lastIndex=i;
        }
    }
    //storing from last element to first so at last reverse it 
    vector<int>lisorder;
    lisorder.push_back(nums[lastIndex]) ; 
    
    //Now,backtrack using hash 
    while(hash[lastIndex]!=lastIndex){
        lastIndex=hash[lastIndex];
        lisorder.push_back(nums[lastIndex]) ;
    }
    //reverse now 
    reverse(lisorder.begin(),lisorder.end());

  cout<< "LENGTH OF LIS " << lenOfLIS << "\n" ; 

  cout<< "PRINTING LIS\n";
for(auto it : lisorder) cout<< it << " ";
}
   //Approach-7 Binary Search    
   //Time Complexity: O(N*LOGN) : We iterate over the array of size N and in every iteration, we perform a binary search which takes logN time.
   //Space Complexity: O(N) : We are using an extra array of size N to store the temp variable.
   
   int binarySearch(vector<int>&nums){
       int n=nums.size();
        vector<int>lis ; //it indicates length of lis but we can't print its element as they don't indicate element belonging to LIS
        //initially element which is at 0th index is a part of lis length = 1 
        lis.push_back(nums[0]);
        int lenOfLIS=1;
        for(int ind=1;ind<n;ind++){
                 //WE OVERWRITE ELEMENTS IN A SINGLE SUB-SEQUENCE
                //AND SAVE SPACE AS WE DON'T CREATE SUB-SEQUENCE MULTIPLE TIMES
              
               //FIND WHETHER TO OVER-WRITE ELEMENT OR INSERT IT AT LAST WHEN INCREASING using lis 
               if(nums[ind] > lis.back()  ) {
                   lis.push_back(nums[ind]);
                   lenOfLIS++;
               }
               else{
                   //OVERWRITE USING Binary Search 
                   //OVERWRITE the first element greater than or equal to nums[ind] 
                   int pos = lower_bound(lis.begin(),lis.end(),nums[ind])-lis.begin();
                   lis[pos]=nums[ind] ;
               }
         }
        return lenOfLIS; //lis.size();
   }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        printLIS(n,nums);
        //return solve(0,-1,nums); //Approach-1 Recursion
         
     //   vector<vector<int>>dp(n,vector<int>(n+1,-1));//co-ordinate shift done[Right Shifting of index] as prev=-1 can't be represented 
    //    return solve2(0,-1,nums,dp); //Approach-2 Memoization

    //    vector<vector<int>>dp(n+1,vector<int>(n+2,-1));//co-ordinate shift done[Right Shifting of index] as prev=-1 can't be represented 
    //    return solve3(n,n+1,nums,dp); //Approach-2 Memoization

    //    return tabulation(nums); //Approach-3 tabulation 
    //    return tabulation2(nums); //Approach-3 tabulation 
    //    return tabulationWithSpaceOptimization(nums) ;   //Approach-4 tabulationWithSpaceOptimization 
    //  return tabulationWithSpaceOptimization2(nums) ;   //Approach-4 tabulationWithSpaceOptimization 
    //    return tabulationWithSpaceOptimization3(nums) ; //Approach-5 tabulationWithSpaceOptimization Using one Array
    //   return tabulationWithSpaceOptimization4(nums) ;   //Approach-5 tabulationWithSpaceOptimization Using one Array
      
   // return TabulationAlgorithm(nums); //Approach-6  Tabulation algorithm
      return binarySearch(nums); //Approach-7  binary Search  
    }
};

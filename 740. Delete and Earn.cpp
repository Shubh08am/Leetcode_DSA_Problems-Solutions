class Solution {
public:
    unordered_map<int,int>freq;

    //Approach 1 :- Recursion
    int solve(int i,vector<int>&nums){
        int n = nums.size();
        if(i>=n){
            return 0;
        }
        //As, nums is sorted see for i+1th element as we need to neglect it if we pick ith element
        //i-1th already neglected via sorting 
        
        //See,how many times to pick via freq of that element
        int pick = freq[nums[i]]*nums[i] ; 
        int posForPick = i + freq[nums[i]]; //as ith picked freq[nums[i]] times see nextPosition now
        int elementPicked = nums[i] ; 

        //skipping the ith element 
        int notPick = solve(i+1,nums);
     
        //Now,skip i+1th element and go to i+2th element position for picking 
        while(posForPick<n && nums[posForPick]==elementPicked+1){
            posForPick++;
        }
       
        //See,total for pick now 
        pick+=solve(posForPick,nums); 

        return max(pick,notPick); //take maximum one
    }
     //Approach 4 :- Recursion :- Without Sorting 
     int solve4(int i,vector<int>&nums){
           if(i<=0) return 0;

           int pick = i*freq[i] ; 
           //than skip adjacent as going from max elem --> min elem --> see only left neighbour as no right neighbour needed 
           if(i>1) pick+=solve4(i-2,nums);

           int notPick = solve4(i-1,nums);


           return max(pick,notPick) ;
     }

     //Approach 2 :- Memoization
    int solve2(int i,vector<int>&nums,vector<int>&dp){
        int n = nums.size();
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];

        //As, nums is sorted see for i+1th element as we need to neglect it if we pick ith element
        //i-1th already neglected via sorting 
        
        //See,how many times to pick via freq of that element
        int pick = freq[nums[i]]*nums[i] ; 
        int posForPick = i + freq[nums[i]]; //as ith picked freq[nums[i]] times see nextPosition now
        int elementPicked = nums[i] ; 

        //skipping the ith element 
        int notPick = solve2(i+1,nums,dp);
     
        //Now,skip i+1th element and go to i+2th element position for picking 
        while(posForPick<n && nums[posForPick]==elementPicked+1){
            posForPick++;
        }
       
        //See,total for pick now 
        pick+=solve2(posForPick,nums,dp); 

        return dp[i]=max(pick,notPick); //take maximum one
    }
    //Approach 5 :- Memoization :- Without Sorting 
     int solve5(int i,vector<int>&nums,vector<int>&dp){
           if(i<=0) return 0;
           
           if(dp[i]!=-1) return dp[i];

           int pick = i*freq[i] ; 
           //than skip adjacent as going from max elem --> min elem --> see only left neighbour as no right neighbour needed 
           if(i>1) pick+=solve5(i-2,nums,dp);

           int notPick = solve5(i-1,nums,dp);


           return dp[i]= max(pick,notPick) ;
     }
    //Approach 3 :- Tabulation 
    int tabulation(int mx,vector<int>&nums){
        vector<int>dp(mx+1,0);

    //    dp[0]=freq[0]; //as freq[0] always 0
         
        for(int i=1;i<=mx;i++){
            int pick = freq[i]*i;
            if(i>1) pick+=dp[i-2];

            int notPick = dp[i-1] ; 

            dp[i]=max(pick,notPick);
        }
        return dp[mx];
    }
    int deleteAndEarn(vector<int>& nums) {
    //    sort(nums.begin(),nums.end()); //for Approach 1-3 used
        for(auto&val:nums){
            freq[val]++;
        }
      //  return solve(0,nums);  //Approach 1 :- Recursion
    //  vector<int>dp(100001,-1);
    //  return solve2(0,nums,dp); //Approach 2 :- Memoization 

  //  return tabulation(nums.back(),nums); //Approach 3 :- Tabulation
       
       int mx = *max_element(nums.begin(),nums.end());
     //   return solve4(mx,nums);  //Approach 4 :- Recursion

        vector<int>dp(mx+1,-1);
        return solve5(mx,nums,dp);//Approach 5 :- Memoization 
    }
};

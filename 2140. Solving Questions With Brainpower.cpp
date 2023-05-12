class Solution {
public:
    //Approach-1 Recursion Time Complexity: O(2^N) Space Complexity: O(N)
    long long solve(int ind,vector<vector<int>>& questions){
        int n=questions.size(); 
        if(ind>=n) return 0;

        //EXPLORE ALL WAYS 
        long long int notTake = 0+solve(ind+1,questions);
        long long int take = questions[ind][0] + solve(ind+questions[ind][1]+1,questions);

        //RETURN MAX OF ALL WAYS EXPLORED
        return max(take,notTake);
    }
     //Approach-2 Memoization :- Time Complexity: O(N) Space Complexity: O(N) + O(N)
    long long solve2(int ind,vector<vector<int>>& questions,vector<long long int>&dp){
        int n=questions.size(); 
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind] ; 
        //EXPLORE ALL WAYS 
        long long int notTake = 0+solve2(ind+1,questions,dp);
        long long int take = questions[ind][0] + solve2(ind+questions[ind][1]+1,questions,dp);

        //RETURN MAX OF ALL WAYS EXPLORED
        return dp[ind] = max(take,notTake);
    }
    //Approach-3 Tabulation :- Time Complexity: O(N) Space Complexity: O(N)
    long long tabulation(vector<vector<int>>& questions){
        int n=questions.size(); 
        vector<long long int>dp(n+1,0); 
         
        for(int ind=n-1;ind>=0;ind--){
            
                long long int notTake = 0+dp[ind+1];
                long long int take =  questions[ind][0] ; 
                if(ind+questions[ind][1]+1<n) take+=dp[ind+questions[ind][1]+1];

                //RETURN MAX OF ALL WAYS EXPLORED
                  dp[ind] = max(take,notTake);
         }
        return dp[0];
    }

    long long mostPoints(vector<vector<int>>& questions) {
        //[points,skip] 
        // DP -> Take , NotTake with skip days condition on taking 
 
       // return solve(0,questions);  //Approach-1 Recursion
        int n=questions.size(); 
      //  vector<long long int>dp(n,-1);   
     //   return solve2(0,questions,dp);    //Approach-2 Memoization

        return tabulation(questions) ; ////Approach-3 Tabulation
    }
};

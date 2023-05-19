class Solution {
public:
    //Approach-2 Memoization :- 
    /*
    Time Complexity: O(N3), There are total N2 no. of states. And for each state, we are running a partitioning loop roughly for N times.

    Space Complexity: O(N2) + Auxiliary stack space of O(N), N2 for the dp array we are using. 
     */
    int solve(int i,int j,vector<int>& nums,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j]; 

        int maxScore = INT_MIN; 
        //try out all partition 
        for(int ind=i;ind<=j;ind++){
            //independent sub-problems -> partition from back 
            int score =  nums[i-1]*nums[ind]*nums[j+1]+solve(i,ind-1,nums,dp)+solve(ind+1,j,nums,dp);

            maxScore=max(maxScore,score);
        }
        return dp[i][j]=maxScore;
    }
     //Approach-3 Tabulation :- 
     /*
        Time Complexity: O(N3), There are total N2 no. of states. And for each state, we are running a partitioning loop roughly for N times.

    Space Complexity: O(N2), N2 for the dp array we are using.
*/
    int tabulation(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1); 
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));

        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j) continue; 
                 int maxScore = INT_MIN; 
                //try out all partition 
                for(int ind=i;ind<=j;ind++){
                    //independent sub-problems -> partition from back 
                    int score =  nums[i-1]*nums[ind]*nums[j+1]+dp[i][ind-1]+dp[ind+1][j];
                    maxScore=max(maxScore,score);
                }
                dp[i][j]=maxScore;
            }
        }
    return dp[1][n] ;
    }
    int maxCoins(vector<int>& nums) {
        //partition from first to last element possible 
        //for first and last element insert additional number = 1 so that they can be partitioned 
        int n=nums.size();

        return tabulation(nums) ;  //Approach-3 Tabulation 

        nums.push_back(1); 
        nums.insert(nums.begin(),1);

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(1,n,nums,dp); //Approach-2 Memoization
    }
};

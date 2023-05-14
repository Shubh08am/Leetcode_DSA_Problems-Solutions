class Solution {
public:
/* REFER :-
https://leetcode.com/problems/maximize-score-after-n-operations/solutions/3521675/image-explanation-fastest-complete-intuition-c-java-python/?orderBy=most_votes
*/
    int solve(int operation,int mask,vector<int>& nums,vector<int>&dp){
        int n=nums.size();
        int requiredOperation = n/2; 

        if(operation>requiredOperation) return 0; 

        if(dp[mask]!=-1) return dp[mask] ; 

        //TRY ALL PAIRS :- 1 INDICATE CHOOSEN AND 0 INDICATE NOT CHOOSEN 
        for(int i=0;i<n;i++){
            //IF ALREADY CHOOSEN(BIT IS SET) -> CAN'T BE CHOOSEN AGAIN 
            if((mask & (1<<i))) continue;
            for(int j=i+1;j<n;j++){
                 //IF ALREADY CHOOSEN(BIT IS SET) -> CAN'T BE CHOOSEN AGAIN 
                    if((mask & (1<<j))) continue;

                    //WHEN BIT NOT SET CHOOSE IT 
                    //THAN MAKE THAT BIT SET BY USING OR(|) or XOR(^) BITWISE OPERATION   
                    int newMask = (1<<i) ^ (1<<j) ^ mask ; 
                    
                    // CALCULATE THE SCORE 
                    int score = operation* __gcd(nums[i],nums[j])+solve(operation+1,newMask,nums,dp) ;
                    dp[mask]=max(dp[mask],score) ;
            }
        }
    return dp[mask];
    }
    int maxScore(vector<int>& nums) {
        //DP ON BIT-MASKING 
         int N = nums.size();
        // 2 ^ N -> number of unique possible combiantions of take or notTake
        int maskValue = (1 << N);  // 2 ^ N
        vector<int> dp(maskValue, -1); 
        return solve(1,0,nums,dp);
    }
};

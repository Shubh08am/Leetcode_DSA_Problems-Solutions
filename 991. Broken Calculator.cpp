class Solution {
public:
    //Approach 1:- Recursion
    int solve(int target,int startValue){
        if(startValue>=target){
            return startValue-target;
        }

        //odd case
        if(target&1){
            return 1 + solve(target+1,startValue);
        }
        //even case:- 
        return 1 + solve(target/2,startValue);

    }
   //Approach 2:- Memoization
    int solve2(int target,int startValue,unordered_map<int,int>&dp){
        if(startValue>=target){
            return startValue-target;
        }
        if(dp.count(target)) return dp[target];

        //odd case
        if(target&1){
            return dp[target] = 1 + solve2(target+1,startValue,dp);
        }
        //even case:- 
        return dp[target] = 1 + solve2(target/2,startValue,dp);

    }
   //Approach 3: Greedy
    int greedy(int startValue, int target){
        int ans=0;
        //Greedy Approach:- Always target can be reached therefore start from target only and move to startValue 

        while(target>startValue) {
            if(target&1) {target++; ans++; }
             target>>=1;
          //  cout<<target<<" ";
            ans++; 
             
        }

        //for startValue>target
        while(target!=startValue){
            target++;
         //   cout<<target<<" ";
            ans++;
        }
        return ans;
    }
    int brokenCalc(int startValue, int target) {
        
       // return solve(target,startValue); //Approach 1:- Recursion 

      unordered_map<int,int>dp; //as vector of 1e9 can't be used
      return solve2(target,startValue,dp); //Approach 2:- Memoization

    //   return greedy(startValue,target);
    }
};

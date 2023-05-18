class Solution {
public:
    //Approach-1 Recursion Time Complexity: EXPONENTIAL
    int solve(int i,int k,vector<int>& arr){ 
        int n = arr.size(); 
        if(i==n) return 0 ;  

        int noOFElement = 0 , maxElement=0 , maxSum=0; 
        int len = min(i+k,n) ; 
        for(int ind=i;ind<len;ind++){
             maxElement=max(maxElement,arr[ind]);
            noOFElement++;
            int value= noOFElement*maxElement + solve(ind+1,k,arr);

            maxSum=max(maxSum,value);
        }
        return maxSum;
    }
    //Approach-2 Memoization :- 
    /*
    Time Complexity: O(N*k)
    Reason: There are a total of N states and for each state, we are running a loop from 0 to k.

    Space Complexity: O(N) + Auxiliary stack space O(N)
    Reason: First O(N) for the dp array we are using.
    */
     int solve2(int i,int k,vector<int>& arr,vector<int>& dp){ 
        int n = arr.size(); 
        if(i==n) return 0 ;  

        if(dp[i]!=-1) return dp[i] ; 

        int noOFElement = 0 , maxElement=0 , maxSum=0; 
        int len = min(i+k,n) ; //SO THAT IT IS LESS THAN N 
        //K PARTITION DONE -> RUNS FOR K TIMES
        for(int ind=i;ind<len;ind++){
             maxElement=max(maxElement,arr[ind]);
            noOFElement++;
            int value= noOFElement*maxElement + solve2(ind+1,k,arr,dp);

            maxSum=max(maxSum,value);
        }
        return dp[i]=maxSum;
    }
    //Approach-3 Tabulation :- 
    /*Time Complexity: O(N*k)
    Reason: There are a total of N states and for each state, we are running a loop from 0 to k.

    Space Complexity: O(N)
    Reason: O(N) for the dp array we are using.
*/
    int tabulation(vector<int>& arr, int k){
         int n = arr.size(); 
         vector<int>dp(n+1,-1); 
         dp[n]=0; //base case 

         for(int i=n-1;i>=0;i--){
              int noOFElement = 0 , maxElement=0 , maxSum=0; 
                int len = min(i+k,n) ; //SO THAT IT IS LESS THAN N 
                //K PARTITION DONE -> RUNS FOR K TIMES
                for(int ind=i;ind<len;ind++){
                    maxElement=max(maxElement,arr[ind]);
                    noOFElement++;
                    int value= noOFElement*maxElement + dp[ind+1];

                    maxSum=max(maxSum,value);
                }
                 dp[i]=maxSum;
        }
    return dp[0];
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       int n = arr.size(); 

      // return solve(0,k,arr) ;  //Approach-1 Recursion

     // vector<int>dp(n,-1); 
     //  return solve2(0,k,arr,dp) ; //Approach-2 Memoization 

     return tabulation(arr,k) ; //Approach-3 Tabulation 
    }
};

class Solution {
public:
    //Approach-1 Recursion Time Complexity: O(n!)
    int solve(vector<int>& nums1, vector<int>& nums2,int ind){
        int n = nums1.size() ; 
        if(ind>=n) return 0 ; 

        int xorr = INT_MAX; 

        //TRY EVERY COMBINATION OF XOR 
        for(int i=0;i<n;i++){
            //after we take the value we assigned it to -1 so that we don't take it again 
            if(nums2[i]!=-1){
                int oldVal=nums2[i]; //so that we can restore later 
                int roxx = nums1[ind]^nums2[i]; 
                nums2[i]=-1; //used 

                //make a recursion call now 
                int res = roxx + solve(nums1,nums2,ind+1);
                xorr = min(xorr,res);
                //BACKTRACK i.e restore nums2[i] value 
                nums2[i]=oldVal;
            }
        }
        return xorr;
    }
   //Time complexity is O(n*2^n)
     int solve2(vector<int>& nums1, vector<int>& nums2,int ind,int mask,vector<vector<int>>&dp){
        int n = nums1.size() ; 
        if(ind>=n) return 0 ; 
        if(dp[ind][mask]!=-1) return dp[ind][mask];

        int xorr = INT_MAX; 

        //TRY EVERY COMBINATION OF XOR 
        for(int i=0;i<n;i++){
            //IF ALREADY SET BIT(MASK=1) WE CAN'T TAKE IT 
            if(mask & (1<<i)) continue;
                 int roxx = nums1[ind]^nums2[i]; 
                //compute new mask now :- thus set the bit using OR(|) or XOR(^) Bitwise Operator 
                int newMask = (1<<i) ^ mask ;

                //make a recursion call now 
                int res = roxx + solve2(nums1,nums2,ind+1,newMask,dp);
                xorr = min(xorr,res);
         }
        return dp[ind][mask]=xorr;
    }

    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
      //DP WITH BIT-MASKING 
        
      //  return solve(nums1,nums2,0) ;  //BRUTE FORCE Approach-1 Recursion

      int n = nums1.size() ; 
      vector<vector<int>>dp(n,vector<int>(1<<n,-1));
      return solve2(nums1,nums2,0,0,dp) ;
    }
};

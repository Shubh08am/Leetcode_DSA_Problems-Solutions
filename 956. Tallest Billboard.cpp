class Solution {
public:
    int solve(int ind,int lenOfRod1,int lenOfRod2,vector<int>& rods){
        int n = rods.size();

        if(ind==n) {
           // cout<<lenOfRod1<<" "<<lenOfRod2<<"\n";
            if(lenOfRod2==lenOfRod1) return lenOfRod1;
            else return INT_MIN;
        }
        
        int pick1 =   solve(ind+1,lenOfRod1,lenOfRod2+rods[ind],rods) ;
        int pick2 =   solve(ind+1,lenOfRod1+rods[ind],lenOfRod2,rods) ;
        int pick = max(pick1,pick2) ;
        int notPick = solve(ind+1,lenOfRod1,lenOfRod2,rods);
       // cout<<pick<<" "<<notPick<<"\n";
        return max(pick,notPick) ; 
    }

    int solve2(int ind,int diff,vector<int>&rods,vector<vector<int>>&dp){
        int n = rods.size() ;
        if(ind>=n){
            if(diff==0) return 0;
            else return INT_MIN;
        }

        if(dp[ind][diff+5000]!=-1) return dp[ind][diff+5000];
         // diff = num1 - nums2
      //add in support 1
    // (nums1 + rods[idx]) - nums2 = (nums1 - nums2) + rods[idx]   = diff + rods[idx]
        int pick1 =   rods[ind] + solve2(ind+1,diff+rods[ind],rods,dp) ;
    //add in support 2
    // nums1 - (nums2 + rods[idx]) = (nums1 - nums2) - rods[idx] = diff - rods[idx]
        int pick2 =    rods[ind] + solve2(ind+1,diff-rods[ind],rods,dp) ;
        int pick = max(pick1,pick2) ;
        int notPick = solve2(ind+1,diff,rods,dp);

        return dp[ind][diff+5000] = max({pick,notPick}) ;
    }
    int tallestBillboard(vector<int>& rods) {
        // pick and not pick 
       // return solve(0,0,0,rods) ; 
        int n = rods.size() ;
        vector<vector<int>>dp(n,vector<int>(10001,-1));
        return solve2(0,0,rods,dp)/2;
    }
};

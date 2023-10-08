class Solution {
public:
    int solve(int ind1,int ind2,vector<int>& nums1, vector<int>& nums2,vector<vector<int>>&dp) {
        int n=nums1.size(),m=nums2.size();
        //decide when to return INT_MIN and when 0 
        //this works only when +ve result  
        if(ind1>=n || ind2>=m) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2]; 
        int res=INT_MIN;
        int first=nums1[ind1]*nums2[ind2]+solve(ind1+1,ind2+1,nums1,nums2,dp) ; 
        int second=solve(ind1,ind2+1,nums1,nums2,dp) ; 
        int third=solve(ind1+1,ind2,nums1,nums2,dp) ; 
        res=max(res,max({first,second,third}));
        return dp[ind1][ind2] = res;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        //DP -> LCS PATTERN 
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1)) ; 
        int ans_pos =  solve(0,0,nums1,nums2,dp); 
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        if(nums1[n-1]<0 && nums2[0]>0){
            return nums1[n-1]*nums2[0] ;
        }
        if(nums2[m-1]<0 && nums1[0]>0){
            return nums2[m-1]*nums1[0] ;
        }
        return ans_pos;
    }
};

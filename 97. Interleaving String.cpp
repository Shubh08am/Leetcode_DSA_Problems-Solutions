class Solution {
public:
    bool func(int indS1,int indS2,string &s1,string &s2,string &s3,vector<vector<int>>&dp){
        int n = s1.size() , m = s2.size() ;

        if(indS1==n && indS2==m) {
            return true;
        }

        if(dp[indS1][indS2]!=-1) return dp[indS1][indS2];

        bool pickS1=false;
        if(indS1<n&&s3[indS1+indS2]==s1[indS1]){
             pickS1=func(indS1+1,indS2,s1,s2,s3,dp);
        }
        bool pickS2=false;
        if(indS2<m&&s3[indS1+indS2]==s2[indS2]){
             pickS2=func(indS1,indS2+1,s1,s2,s3,dp);
         }
        return dp[indS1][indS2]=pickS1 || pickS2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size() , m = s2.size() , l = s3.size() ; 
        if(l!=n+m) return false;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1)) ;
        return func(0,0,s1,s2,s3,dp);
    }
};

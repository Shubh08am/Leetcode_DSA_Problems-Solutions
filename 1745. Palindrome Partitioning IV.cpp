class Solution {
public:
    //memoized palindrome check -> for better T.C
    bool isPalindrome(int i,int j,string&s,vector<vector<int>>&pal){
        int &val = pal[i][j]; 
        if(val!=-1) return val ;
        while(i<j){
            if(s[i++]!=s[j--]) return val = false;
        }
    return val = true;
    }
    bool solve(int ind,string&s,int k,vector<vector<int>>&dp,vector<vector<int>>&pal){
        int n=s.size();
        if(ind==n){
             return !k?1:0;
        }
        if(k==0) return 0; //before reaching last position if k=0 not possible
        int &val = dp[ind][k];
        if(val!=-1) return val;
        bool flag=0;
        for(int p=ind;p<n;p++){
            if(isPalindrome(ind,p,s,pal)){
               flag|=solve(p+1,s,k-1,dp,pal);
            }
        }
    return val = flag;
    }
    int tabulation(string&s){
        int n=s.size(),k=3; 
        vector<vector<int>>pal(n+1,vector<int>(n+1,-1));
        vector<vector<int>>dp(n+1,vector<int>(k+1,0)); 
        dp[n][0]=1; 
        for (int i = 0; i < n; i++){
            dp[i][0]=isPalindrome(i,n-1,s,pal);
        }
        for(int ind=n-1;ind>=0;ind--){
            for(int par=1;par<3;par++){
                bool flag=0;
                for(int p=ind;p<n-1;p++){
                    if(isPalindrome(ind,p,s,pal)){
                        flag|=dp[p+1][par-1];
                    }
                }
            dp[ind][par]=flag;
            }
        }
    return dp[0][2];
    }
    bool checkPartitioning(string s) {
        //https://leetcode.com/problems/palindrome-partitioning-iv/solutions/3838671/partition-dp-recursion-memoization-dp/
        int n=s.size(),k=3; 
        vector<vector<int>>pal(n+1,vector<int>(n+1,-1));
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    //  return solve(0,s,2,dp,pal);
        return tabulation(s);
    }
};

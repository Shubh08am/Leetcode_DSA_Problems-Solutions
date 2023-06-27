class Solution {
public:
    int palindrome(string&s,int i,int j){
        int nonEqual = 0 ; 
        while(i<j){
            nonEqual+=s[i++]!=s[j--];
        }
    return nonEqual;
    }

    int solve(int ind,int k,string &s,vector<vector<int>>&dp){
        int n = s.size() ; 
        
        if(ind==n){
            if(k==0) return 0;
            return 1e8;
        }
        //else before reaching last position k partition done 
        if(k==0) return 1e8;

        if(dp[ind][k]!=-1) return dp[ind][k] ;
        
        int change = 1e8 ; 

        for(int partition=ind;partition<n;partition++){
            int nonEqualChar = palindrome(s,ind,partition);
            //check further string now 
            int curr = nonEqualChar + solve(partition+1,k-1,s,dp) ;
            change=min(change,curr);
        }
    return dp[ind][k] = change;
    }
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return solve(0,k,s,dp);
    }
};

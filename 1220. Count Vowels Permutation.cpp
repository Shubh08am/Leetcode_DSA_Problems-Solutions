class Solution {
public:
    const int mod = 1e9+7;
    int solve(char ch,int n,vector<vector<int>>&dp){
        if(n==0) return 1;
        char a = 'a' , i= 'i' , o='o' , u='u' , e='e' ;
        long long ans=0;
        int &val = dp[n][ch] ;
        if(val!=-1) return val;
        if(ch==a){
            ans = (ans+solve(e,n-1,dp))%mod;
        }
        if(ch==e){
            ans = (ans +solve(a,n-1,dp)+solve(i,n-1,dp))%mod;
        }
        if(ch==i){
            ans = (ans +solve(a,n-1,dp)+solve(e,n-1,dp)+solve(o,n-1,dp)+solve(u,n-1,dp))%mod;
        }
        if(ch==o){
            ans = (ans + solve(i,n-1,dp)+solve(u,n-1,dp))%mod;
        }
        if(ch==u){
            ans = (ans + solve(a,n-1,dp))%mod;
        }
    return val = ans;
    }
    int countVowelPermutation(int n) {
        /*
        ae 
        ea ei 
        ia ie io iu
        oi ou 
        ua
        */
        //Now, try all 5 vowels as ch at every position 
        string s = "aeiou";
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(125,-1));
        for(int i=0;i<5;i++){
            ans=(ans+solve(s[i],n-1,dp))%mod;
        }
        return ans;
    }
};

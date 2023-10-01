class Solution {
public:
    bool isValid(string&curr,unordered_map<string,int>&freq){
        return freq.count(curr) ;
    }
    int solve(int ind,string &s, unordered_map<string,int>&freq,vector<int>&dp){
        int n = s.size() ;
        if(ind==n) return 1;
        int ans=0;
        if(dp[ind]!=-1) return dp[ind];
        string curr = s.substr(ind,1);
        if(isValid(curr,freq)){
                ans+=solve(ind+1,s,freq,dp);
        }

        if(ind+1<n){
            string curr2 = s.substr(ind,2);
            if(isValid(curr2,freq)){
                    ans+=solve(ind+2,s,freq,dp);
            }
        }
    return dp[ind]=ans;
    }
    int numDecodings(string s) {
        //try all possible ways  
        int n = s.size() ; 
        unordered_map<string,int>freq; 
        for(char ch='a';ch<='z';ch++){
            freq[to_string((ch-'a')+1)]=1;
        }
        vector<int>dp(n+1,-1);
        return solve(0,s,freq,dp);
    }
};

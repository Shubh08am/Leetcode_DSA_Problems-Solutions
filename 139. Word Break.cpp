class Solution {
public:
    int solve(int ind,string s,vector<string>&wordDict,vector<int>&dp){
        int n = s.size();

        if(dp[ind]!=-1) return dp[ind] ;
        //IF REACHED LAST POSITION IN S THAT MEANS ALL CHAR OF S ARE PRESENT IN wordDict
        if(ind==n) return 1;

        string curr = "";
        bool flag = 0 ; 

        for(int i=ind;i<n;i++){
            curr+=s[i];
            //IF THIS SUB-STRING IS FOUND IN wordDict
            auto it = find(wordDict.begin(),wordDict.end(),curr) ;
            if(it!=wordDict.end()){
                flag|= solve(i+1,s,wordDict,dp);
            }
        }
    return dp[ind]=flag ;
    }
    int tabulation(string s, vector<string>& wordDict){
        int n = s.size();
        vector<int>dp(n+1,0);

        //BASE CASE 
        dp[n]=1;

        for(int ind=n-1;ind>=0;ind--){
            string curr = "" ; 
            bool flag = 0 ; 
            for(int i=ind;i<n;i++){
                curr+=s[i];
                auto it = find(wordDict.begin(),wordDict.end(),curr) ;
                if(it!=wordDict.end() && dp[i+1]){
                    dp[ind]=1;
                    break;
                }
             }
        }
    return dp[0] ;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int>dp(n+1,-1);
       // return solve(0,s,wordDict,dp);
       return tabulation(s,wordDict);
    }
};

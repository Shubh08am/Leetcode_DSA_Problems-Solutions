class Solution {
public:
    //Memoization + Recursion
    int solve(int ind , string s , unordered_set<string>&Dict,vector<int>&dp){
        int n = s.size() ; 

        if(ind==n) {
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind] ; 
        string curr = "" ; 
        int req = n , miniReq = n; 

        for(int i=ind;i<n;i++){
            curr+=s[i] ; 

            //NOW, CHECK WHETHER CURR IS PRESENT IN DICT 
            //IF NOT ADD IT LENGTH AND MAKE FURTHER CALL 
            if(Dict.count(curr)) {
                req=0;
            }
            if(!Dict.count(curr)){
                req=curr.size();
            }
            //FURTHER CALL 
            req+=solve(i+1,s,Dict,dp) ; 

            miniReq = min(miniReq,req);
        }
    return dp[ind] =  miniReq;
    }
    
    int tabulation(string s, vector<string>& dictionary) {
        unordered_set<string>Dict(dictionary.begin(),dictionary.end()) ; 
        int n = s.size();
        vector<int>dp(n+1,0);

        for(int ind=n-1;ind>=0;ind--){
            string curr = "" ; 
            int miniReq = n , req=n; 
            for(int i=ind;i<n;i++){
                 curr+=s[i] ; 
                if(Dict.count(curr)){
                    req=0;
                }
                if(!Dict.count(curr)){
                    req=curr.size();
                }
                req+=dp[i+1] ; //FURTHER CALL 

                miniReq = min(miniReq,req);
              //  cout<<req<<" "<<miniReq<<"\n";
            }
        dp[ind] = miniReq;
        }
    return dp[0] ;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string>Dict(dictionary.begin(),dictionary.end()) ; 
        int n = s.size();
        vector<int>dp(n+1,-1);
      //  return solve(0,s,Dict,dp) ; 
        return tabulation(s,dictionary);
    }
};

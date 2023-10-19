class Solution {
public:
    const int mod = 1e9+7;
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int>dp(n+1,0); 
        dp[0]=1;
        vector<int>lastPos(26,-1);
        for(int i=0;i<n;i++){
            //NO REPETITION 
             // Number of subsequences with substring s[0..i]
            int ch = s[i]-'a';
            if(lastPos[ch]==-1){
                dp[i+1] = (1ll*dp[i]*2)%mod ; 
            }
            //REPETITION 
            // If current character has appeared before, then remove all subsequences
            // ending with previous occurrence.
            if(lastPos[ch]!=-1){
              //  cout << (ch+'a')<< " "<<lastPos[ch] << "\n";
                dp[i+1] = (((1ll*dp[i]*2)%mod - dp[lastPos[ch]])+mod)%mod;
            }      
            // Mark occurrence of current character
            lastPos[ch]=i;
        }
    return (--dp[n]+mod)%mod; //"" empty subsequence removed
    }
};

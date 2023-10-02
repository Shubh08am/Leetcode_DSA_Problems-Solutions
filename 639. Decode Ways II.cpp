const int mod = 1e9+7;
class Solution {
public:
    int solve(int ind,string &s,vector<int>&dp){
        int n = s.size() ; 
        if(ind==n) return 1;
        if(s[ind]=='0') return 0;
        if(dp[ind]!=-1) return dp[ind]; 
        long long ways=0; 

        //CONSIDERING ONE CHARACTER CONTRIBUTION
        int factor = 1; 
        if(s[ind]=='*') factor=9; 
        ways+=(1ll*factor*solve(ind+1,s,dp)); 

        //CONSIDERING TWO CHARACTER  CONTRIBUTION
        if(ind+1<n){    
            int factor=0;
            char curr = s[ind] , next = s[ind+1]; 
            
            //CASE 5 & 6    
            if(curr=='*'){
                if(next=='*'){
                    factor=15;
                }
                //* (7-9) -> 17 18 19 i.e only 1 choice
                else if(next>='7'){
                    factor=1;
                }
                 //* (1-6)-> 1_ 2_ i.e only 2 choice
                else if(next<='6'){
                    factor=2;
                }
            }
             else if(curr=='2'){
                if(next=='*'){
                    factor=6;
                }
                else if(stoi(s.substr(ind,2))<=26){
                        factor=1;
                }
            }
            else if(curr=='1'){
                if(next=='*'){
                    factor=9;
                }
                else if(stoi(s.substr(ind,2))<=26){
                        factor=1;
                }
            }
            ways+=(1ll*factor*solve(ind+2,s,dp));
        }
        // cout<<ways<<"\n";
        return dp[ind]=(ways)%mod;
    }
    int numDecodings(string s) {
        /* Possible cases :- Taking 2 position contribution combined as 1 position handled easily 
        [1] 1 0-9  -> 9 contribution 
        [2] 1 * -> 9 contribution
        [3] 2 0-6 -> 6 contribution
        [4] 2 * -> 6 contribution
        [5] * 0-9 -> XX contribution
        [6] * * -> 15 contribution
        */
        int n = s.size() ; 
        vector<int>dp(n+1,-1);
        return solve(0,s,dp);
    }
};

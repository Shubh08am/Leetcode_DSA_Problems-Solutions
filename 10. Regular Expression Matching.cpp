/*
s="abc"
p="c*abc"
true

s="aab"
p="c*a*b"
true
s = "aab" = "c"*0+"a"*2+"b"
*/
class Solution {
public:
    bool solve(int ind1,int ind2,string &s, string &p,vector<vector<bool>>&dp) {
        int n=s.size() ,m=p.size();
        bool flag=0; 
        if(ind1==0 && ind2==0) return true;
        if(ind2==0 && ind1!=0) return false;
        if(ind1==0 && ind2!=0){
            //i-=2 because before * we have a-z character always 
            //and we either replace * by it or by zero character 
            //solve(ind1,ind2-2,s,p,dp);
            for(int i=ind2-1;i>=0;i-=2){
                if(p[i]!='*') return false;
            }
        return true;
        }
        if(dp[ind1][ind2]!=-1) dp[ind1][ind2];
        if(s[ind1-1]==p[ind2-1] || p[ind2-1]=='.'){
            flag=flag|solve(ind1-1,ind2-1,s,p,dp);
        }
        if(p[ind2-1]=='*'){
            /*
            s="mississippi"
            p="mis*is*ip*."
            true
            */
            //not matching case
            /*
            s="cabc"
            p="c*a*abc"
            true
            when p[3] encounter ignore that * i.e not-matching and call for (ind1=1,ind2=2)
            than (ind1-1=0 and ind2-2=0 will match)
            */
            
            flag=flag||solve(ind1,ind2-2,s,p,dp);
            /*
            s="cccabc" p = "c*abc" true
            so till p[0] matches character from s[2] -> s[1] ->s[0] ->don't move p[0] 
            */
            //matching case
            if(s[ind1-1]==p[ind2-2] || p[ind2-2]=='.'){
                flag=flag||solve(ind1-1,ind2,s,p,dp);
            }
         }
    return dp[ind1][ind2]=flag;
    }
    bool isMatch(string s, string p) {
        int n=s.size() ,m=p.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,-1)) ; 
        return solve(n,m,s,p,dp);
    }
};

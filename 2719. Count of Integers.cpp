class Solution {
public:  
    int dp[2][23][201] ; 
    const int mod=1e9+7;
    string subtractOne(string &s){
        reverse(s.begin(),s.end()) ; 
        int first_non_zero=0;
        while(s[first_non_zero]=='0') first_non_zero++; 
        s[first_non_zero]--;
        //from 0 to first_non_zero all becomes 9 
        //200-1 = 199
        //002 --> 001 -> 991 -> 199 
        for(int i=0;i<first_non_zero;i++) s[i]='9' ; 
        //100-1 = 99
        //100 --> 001 -> 000 -> 990 -> 99 
        while(!s.empty() && s.back()=='0') s.pop_back() ; 
        if(s.empty()) s="0" ;
        reverse(s.begin(),s.end()) ; 
    return s;
    }
    int solve(bool is_smaller,int ind,int sum,int min_sum,int max_sum,string &s){
        if (ind == s.size()) {
            return sum>= min_sum && sum <= max_sum;
        }

        int &ans = dp[is_smaller][ind][sum];
        if (ans != -1) return ans;
        
        int val = 0;
        int start = 0, end = is_smaller?9:(s[ind]-'0');
        
        for (int k=start;k<=end;k++) {
            bool new_is_smaller = is_smaller?true:(k!=end) ;
            val = (val + solve(new_is_smaller,ind+1,sum+k,min_sum,max_sum,s)) % mod;
        }
        return ans=val;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        // till num2 - till num1-1 
        memset(dp,-1,sizeof(dp)) ; 
        int second = solve(false,0,0,min_sum,max_sum,num2) ; 

        string prevNum1 = subtractOne(num1);
        memset(dp,-1,sizeof(dp)) ; 
        int first = solve(false,0,0,min_sum,max_sum,prevNum1) ;
        int ans = (second-first+mod)%mod;
    return ans; 
    }
};

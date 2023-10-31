class Solution {
public:
    const int mod = 1e9+7;
    int dp[2][2][10][101] ; 
    string subtractOne(string &s){
        if(s=="1") return "0" ;
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
        while(s.back()=='0') s.pop_back() ; 
        if(s.empty()) s="0" ;
        reverse(s.begin(),s.end()) ; 
    return s;
    }
    int solve(bool is_smaller,bool is_started,int ind,int prevVal,string &s){
        int n=s.size();
        if(ind==n) return 1; 

        int &ans = dp[is_started][is_smaller][prevVal][ind] ;
        if(ans!=-1) return ans;

        int val=0; 
        int start=0,end=(is_smaller?9:(s[ind]-'0')) ;

        for(int k=start;k<=end;k++){
            //is_started needed for 0th position case 
            if(is_started && abs(k-prevVal)!=1) continue; 

            bool new_is_started = is_started?true:(k!=0) ; 
            bool new_is_smaller = is_smaller?true:(k!=end) ;

            val=(val+solve(new_is_smaller,new_is_started,ind+1,k,s))%mod;
        }
        return ans=val;
    }
    int countSteppingNumbers(string low, string high) {
       memset(dp,-1,sizeof(dp)) ; 
       int second = solve(false,false,0,0,high) ; 
       //cout<<second;

        memset(dp,-1,sizeof(dp)) ; 
       string prevLow = subtractOne(low) ; 
       int first = solve(false,false,0,0,prevLow) ;
       int ans = (second-first+mod)%mod;
       return ans;
    }
};

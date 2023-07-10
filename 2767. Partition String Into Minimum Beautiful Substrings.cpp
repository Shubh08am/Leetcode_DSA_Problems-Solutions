#define ll long long
class Solution {
public:
    bool isPowerof5(int n){
       if (n < 125)  return n == 1 || n == 5 || n == 25;
       if (n % 125 != 0) return 0;
       return isPowerof5(n / 125);
    }
    ll solve(int i,string&s){
        int n = s.size()  ; 
        if(i==n) return 0;
        //if string start from 0 not possible 
        if(s[i]=='0') return 1e7; 
        
        ll res = 1e7 ; 
        ll m=0;
        
        //find number which are power of 5 from i onwards 
        for(int j=i;j<n;j++){
             m = m*2+(s[j]=='1') ; 
          //  cout<<m<<"\n";
            
            //check for power of 5 
            if(isPowerof5(m)) { 
                //cout<<res<<" ";
                res = min(res, 1+solve(j+1,s)) ; 
            }
        }
        return res ; 
    }    
    int minimumBeautifulSubstrings(string s) {
        return solve(0,s)>=1e7?-1:solve(0,s);
    }
};

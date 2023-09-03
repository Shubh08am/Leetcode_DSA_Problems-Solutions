#define ll long long
#define rep(i, a, b) for (ll i = a; i < b; ++i)
class Solution {
public:
    int minimumOperations(string s) {
       ll ans = INT_MAX;
ll n= s.size() ; 
        ll o=0;
rep(i,0,n){
    if(s[i]=='0') o++;
rep(j,i+1,n){
	ll  value = (s[i]-'0')*10+(s[j]-'0');
	if(value%25==0)
{	ans=min(ans,n-i-2);}
			}		
} 
        if(ans==INT_MAX){
            if(o>0) return n-1;
            else return n;
        }
        return ans;
    }
};

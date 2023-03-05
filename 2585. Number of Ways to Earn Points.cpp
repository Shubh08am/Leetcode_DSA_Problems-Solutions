#define ll long long
const ll mod = 1e9+7;
class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& t) {
       ll n =  t.size() , c=0; 
      vector<int>v(target+1,0);
        v[0]=1;
        
        for(ll i=0;i<n;i++){
            ll val1 = t[i][0] , val2 =  t[i][1]  ; 
            for(ll k=target;k>=val2;k--){
               
                for(ll j=1;j<=val1;j++){
                     ll val3 = j*val2 ; 
                    ll val4 = k-val3 ;  
                    //not able to get  marks 
                    if(val4 < 0) {
                        break;
                    }
                    //else we can get
                 else{ 
                        ll ans = (v[k] + v[val4]%mod)%mod ; 
                        v[k] = ans;
                 } 
                }
            }
        }
        c=v[target];
        return c;
    }
};

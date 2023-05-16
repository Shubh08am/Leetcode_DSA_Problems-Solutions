const int mod = 1e9+7 ;
#define ll long long
class Solution {
public:
    ll binExp2(ll a , ll b){
    ll ans=1;
  while(b>0){
    //see if set-bit 
    if(b&1){
        ans=(ans*a*1LL)%mod;
    }
    a = (a*a*1LL)%mod;  //go to next power
    b>>=1 ; //right-shift the bit
  }
  return ans;
}
    
    int sumOfPower(vector<int>& nums) {
        int n=nums.size();
        vector<ll>num ;
        for(auto it : nums) num.push_back(it) ; 
        
        ll ans=0 , a=0 , c=0;
        sort(num.begin(),num.end()) ; 
        
        for(int i=0;i<n;i++){
            ans=(ans+ (binExp2(num[i],2)) * num[i]%mod)%mod; 
            ans=(ans+ ((a*num[i])%mod)*num[i]%mod)%mod;
            a=(a<<1)%mod;
            a=(a+num[i])%mod;
        }
        return ans;
    }
};

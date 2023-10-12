#define ll long long
const int mod =  1e9+7;
class Solution {
public:
    ll binMultiply(ll a , ll b){
      ll ans=0;   
  while(b>0){
     if(b&1){
        ans=(ans+a)%mod;
    }
    a = (a+a)%mod; 
    b>>=1 ; 
  }
  return ans;
}
//leads to tle many times therefore use next one
ll binExp(ll a , ll b){
    ll ans=1;
  while(b>0){
    if(b&1){
        ans=binMultiply(ans,a) ;
    }
    a = binMultiply(a,a); 
    b>>=1 ; 
  }
  return ans;
} 
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
ll findMaximumSum(vector<int>& nums,ll k){
    vector<ll>dp(32,0);
    for (auto &it : nums) {
        ll ind = 0;
        while (it) {
            if (it & 1)  dp[ind]++;
            it >>= 1;
            ind++;
        }
    }
    priority_queue<ll>pq;
    ll cnt=0;
    ll curr=0;
    ll res=0;
    ll n=nums.size();
    for (int i = 0; i < k; ++i) {
        ll t = 0;
        for (int j = 0; j < 31; ++j) {
            if (dp[j] > 0) {
              //  t = (t+(ll)pow(2,j))%mod;
              //   t = (1ll*(t+binExp(2,j)))%mod;
                  t = (1ll*(t+(1<<j)))%mod;
                 dp[j]--;
            }
        }
     //  cout<<t << " ";
       pq.push(t);
  //      curr=(curr+(1ll*t * t))%mod;
    //    res= res<=curr?curr:res;
       /* if(cnt==k) {
            cout<<cnt<<"\n";
            return res;
        }*/
    }
    while(!pq.empty()){
        ll t = pq.top();
        pq.pop();
        cnt++;
        res=(res+(1ll*t * t))%mod;
        if(cnt==k) break;
    }
    return res;
}
    int maxSum(vector<int>& nums, int k) {
        ll a=findMaximumSum(nums,k)%mod;
      //  cout<<nums.size() << "\n";
       // for(auto it : nums) cout<<it<<" ";
	return a;

    }
};

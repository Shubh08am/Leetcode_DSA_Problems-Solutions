#define ll long long 
const int mod = 1337;
class Solution {
public:
/*
a=2 , n=[5,4,3,2,1]
We have to find 2^(54321)%1337
Basic Rule: (a * b)%c = (a%c * b%c )%c

Now , 2^(54321) = 2^(54320) * 2^1
= ((2^5432)^10) * 2^1
= ([((2^5430) * (2^2)]^10) * 2^1
= [ [ 2^543] ^ 10 * 2^2 ] ^ 10 * 2^1
.
.
.
=[[[(2^5)^10 * 2^4 ]^10 * 2^3 ] ^10 ] * 2^2 ] ^ 10 * 2^1
*/
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

    int superPow(int a, vector<int>& b) {
        ll ans = 1;
        for(int i=0;i<b.size();i++){
           ans=(binExp2(ans,10)*binExp2(a,b[i]))%mod;
         }
        return ans;
    }
};

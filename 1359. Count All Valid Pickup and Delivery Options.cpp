/*
Observation :
n = 1 -> output : 1
n = 2 -> output : 6
for n = 3 we have three pickups and three delivery orders.
if we fix the position of one pickup and one delivery order, than our problem reduce for two pickup and two delivery orders that we have already calculated as 6.

we have : P1 P2 P3 D1 D2 D3
try to fix for P1 and D1 (D1 will be always after P1)
P1 - - - - - : for P1 at position 1, we have five option for D1
- P1 - - - - : four option for D1
- - P1 - - - : three option for D1
- - - P1 - - : two
- - - - P1 - : one
So total we can arrange P1 and D1 in 15 ways for n = 3
than our answer will be 15 * f(2).
we can observe for 15 as : 5 + 4 + 3 + 2 + 1

(2n-1) + (2n-2) + (2n-3) + ...... + 1
(2n*(2n-1))/2
n*(2n-1)
So our final formula will be

f(n) = n*(2n-1)*f(n-1)
*/
const int mod = 1e9+7;
class Solution {
public:
    long long ncr(int n){
        long long num = 1 , prev = 1;
        for(int i=1;i<=n;i++){
            num=(prev*i*(2*i-1))%mod;
            prev=num;
        }
    return num;
    }
    int countOrders(int n) {
        //  permutation and combination 
    return ncr(n);
    }
};

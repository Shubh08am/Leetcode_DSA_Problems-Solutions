#define ll long long
class Solution {
public:
    long long repairCars(vector<int>&p, int k) {
        ll n = p.size();
        ll start = 0 , end = 1e18 , res=0;
        while(start<=end){
            ll mid =  start + (end-start)/2 ; 
            
            ll cnt = 0;
            for(auto it:p){
                cnt += (ll)sqrtl(mid/it);
            }
            
            if(cnt>=k) {
                res=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return res;
    }
};

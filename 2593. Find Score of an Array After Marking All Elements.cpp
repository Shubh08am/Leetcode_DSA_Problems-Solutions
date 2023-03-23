#define ll long long
class Solution {
public:
    long long findScore(vector<int>& nums) {
        ll n = nums.size() , score=0; 
        vector<int>v(n,0) ; 
        map<ll,vector<ll>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int mx=-1; 
        for(auto&x:nums) mx=max(x,mx) ; 
        for(int i=1;i<=mx;i++){
            if(mp.count(i)==0) continue;
             
            for(auto it:mp[i]){ 
            if(!v[it]){
            v[it]=1;
            if(it+1<n) v[it+1]=1;
            if(it>0) v[it-1]=1;
            score+=i;
                }
            }
        }
        return score ;
    }
};

#define ll long long
class Solution {
public:
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
        ll n = r1.size(),ans=0 ; 
         priority_queue<pair<ll,ll>>pq;
        for(int i=0;i<n;i++){
               ll val = r1[i] - r2[i] ;
            pq.push({val,i});
        }
        while(k--){
            ans+=r1[pq.top().second];
             pq.pop();
        }
          while(!pq.empty()){
            ans+=r2[pq.top().second];
            pq.pop();
        }
          return ans;
    }
};

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
       // worker[j] -> se kaam ya barabaar vale difficulty kii profit max hoo 
       //precomputation  
       int n = profit.size() , m = worker.size() , maxi = 0;
       int mx = *max_element(difficulty.begin(),difficulty.end()) ; 
       long long ans = 0 ;
       vector<int>pre(mx+1,0)  ; 
       map<int,int>mp ; 
       for(int i=0;i<n;i++){
           //same difficulty pe different profit tho take max one
           mp[difficulty[i]]=max(profit[i],mp[difficulty[i]]); 
       }
       for(int i=1;i<=mx;i++){
           pre[i] = mp[i];
       }

       /*for(int i=1;i<=mx;i++){
          cout<<pre[i]<<" ";
       }*/
       for(int i=1;i<=mx;i++){
         maxi=max(maxi,pre[i]) ; 
         pre[i]=maxi;
       }
       for(int i=0;i<m;i++){
           if(worker[i]>mx){
               ans+=pre[mx];
           }
           else{
               ans+=pre[worker[i]] ;
           }
       }
       return ans;
    }
};

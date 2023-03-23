#define ll long long
class Solution {
public:
     int rec(int index , vector<int>& n , int k , int m,map<int,int>&vis){
         //base case 
         ll a=0;
         if(index>=m){
             return 1;
         }
         //take not take
         ll u = n[index]-k ;
         if(!vis[u]){
             vis[n[index]]++;
             a = a+rec(index+1,n,k,m,vis);
             //backtrack 
              vis[n[index]]--;
         }
         //agan take answwer 
         a=a+rec(index+1,n,k,m,vis);
         return a;
     }
    int beautifulSubsets(vector<int>& n, int k) {
        ll m = n.size() , c=0 , a=0; 
        sort(n.begin(),n.end());
        map<int,int>vis;
        c =  rec(0,n,k,m,vis)-1;
        return c;
        
        }
};

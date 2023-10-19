#define ll long long 
class Solution {
public:
    const int mod = 12345 ; 
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ; 
        // prefix and suffix 
        vector<int>nums; 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                nums.push_back(grid[i][j]) ;
            }
        }
         int w  = nums.size() ; 
       //   for(auto it : nums) cout<<it << " ";
        vector<ll> ans(w,1); 
        ll product = 1 ; 
        //prffix part
        for(int i=0;i<w;i++){
            ans[i] = (1ll*(1ll*ans[i])*product)%mod ; 
            product=(1ll*(1ll*product)*nums[i])%mod;
        }
        //suffix part
        product=1;
        for(int i=w-1;i>=0;i--){
            ans[i] = (1ll*(1ll*ans[i])*product)%mod ; 
            product=(1ll*(1ll*product)*nums[i])%mod;
        }
   //    for(auto it : ans) cout<<it << " ";
        
        vector<vector<int>>res; 
        vector<int>row;
        for(int i=0;i<ans.size();i++){
            if(row.size()<m)  row.push_back(ans[i]) ; 
            else {res.push_back(row) ; row.clear(); row.push_back(ans[i]);}
        }
         res.push_back(row) ;
        return res;
    }
};

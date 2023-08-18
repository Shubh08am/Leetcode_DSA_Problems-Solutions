#define ll long long
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
       int n = nums.size();
     //  vector<pair<int, int>>vp;
    //   for (int i = 0; i < n; ++i)    vp.push_back({nums[i], i});    
    //   sort(vp.begin(), vp.end());
       set<int>front,back; 
        int res = 1e9; 
        for(int i=0;i<n;i++){
            front.insert(nums[i]) ;
            if(i+x<n){
                ll val = nums[i+x];
                auto pos = front.lower_bound(val) ; 
                
                if(pos==front.end()) continue;
                else{
                int val2 = abs(val- (*pos)) ;
                res = min(res,val2) ;  
                }
            }
            
          
        }
        
        // for [1,2,3,4] x=3 back se traverse krne pe 3 
        for(int i=n-1;i>=0;i--){
            back.insert(nums[i]) ;
            if(i-x>=0){
                ll val = nums[i-x];
                auto pos = back.lower_bound(val) ; 
                
                if(pos==back.end()) continue;
                else{
                int val2 = abs(val- (*pos)) ;
                res = min(res,val2) ; 
                }
            }
            
          
        }
     return res;
    }
};

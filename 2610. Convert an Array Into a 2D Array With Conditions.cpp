class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int>s; int c=0;
        for(auto it : nums) s[it]++ ; 
         vector<vector<int>>ans; 
        int n = s.size() ; 
        if(n==nums.size()){
            ans.push_back(nums);
            return ans;
        }
        
        for(auto it : s){
             c=max(c,it.second) ; 
        }
        vector<vector<int>>r(c) ; 
         for(auto it : nums){
           //  if(it==0) continue;
            r[s[it]-1].push_back(it) ;
             s[it]-=1;
        }
        return r;
    }
};

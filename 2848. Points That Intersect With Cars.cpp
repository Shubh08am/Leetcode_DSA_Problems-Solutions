class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int>v(101,0) ; 
        for(auto it : nums){
            for(auto x = it[0] ; x<=it[1] ; x++) v[x] = 1 ; 
        }
        return count(v.begin(),v.end(),1) ;
    }
};

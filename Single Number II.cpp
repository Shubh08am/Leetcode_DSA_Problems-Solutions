class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp ;
        for(auto i : nums){
           mp[i]++;
            } 
        for(auto t : mp)
            {
            if(t.second==1){
                return t.first ;
                }
            } 
        return -1;
    }
};

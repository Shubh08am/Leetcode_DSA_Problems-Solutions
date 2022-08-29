class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
    vector<int>v;
        for(auto i : nums){
           mp[i]++;
            } 
        for(auto t : mp)
            {
            if(t.second==1){
                v.push_back(t.first) ;
                }
            } 
        return v;
    }
};

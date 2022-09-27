class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums){
            if(!(i&1)) mp[i]++;
        }
        int res = -1 ; int ans=INT_MIN;
        for(auto it:mp){
            if(it.second > ans){
                ans=it.second;
                res= it.first;
            }
        }
        
        return res;
    }
};

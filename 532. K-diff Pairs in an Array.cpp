class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
      map<int,int>mp ; 
      int ans = 0 ;
      for(auto it : nums) mp[it]++;
      for(auto it : nums)  {
        if(k==0){
          ans+=mp[it]>1?1:0;
          mp[it]=0;
          continue;
        }
        if(mp[it+k]>0) {ans++; mp[it+k]=0;}
      }
    return ans;
    }
};

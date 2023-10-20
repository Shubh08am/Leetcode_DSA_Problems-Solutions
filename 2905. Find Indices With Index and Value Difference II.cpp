class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        multiset<pair<int,int>>ms;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i>=indexDifference) ms.insert({nums[i-indexDifference],i-indexDifference});
          if(!ms.empty()){ 
            if(abs(ms.rbegin()->first-nums[i]) >= valueDifference) return {ms.rbegin()->second,i} ;
            if(abs(ms.begin()->first-nums[i]) >= valueDifference) return {ms.begin()->second,i} ;
          }
        }
        return {-1,-1};
    }
};

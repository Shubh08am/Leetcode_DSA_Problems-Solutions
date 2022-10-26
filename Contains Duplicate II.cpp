class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //window size is k
        int i=0,j=0;
        unordered_map<int,int>mp;
        
        while(j<nums.size()){
         mp[nums[j]]++;
       if(mp[nums[j]]==2) return 1;
            
                if(j-i== k) {
                //remove calculation for i
                  mp[nums[i]]--;
                   i++;
                }
                j++;
            }
        return 0;
    }
};

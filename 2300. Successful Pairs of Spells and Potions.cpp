class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        int n = potions.size();
       sort(potions.begin(),potions.end()) ; 
       for(auto&val:spells){
          // long long search = (success+val-1)/val ; //for-taking ceil 
             long long search = ceil(success*1.0/val) ; //or use this 
           //do binary search now 
           int pos = lower_bound(potions.begin(),potions.end(),search) - potions.begin() ;
           ans.push_back(n-pos);
       } 
       return ans;
    }
};

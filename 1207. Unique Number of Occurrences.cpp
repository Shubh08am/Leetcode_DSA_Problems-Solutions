class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        vector<pair<int,int>>unique;
        for(auto it : arr) mp[it]++;

        for(auto it : mp){
           unique.push_back({it.first,it.second});
        }

       for(int i=0;i<unique.size();i++){
                  for(int j=0;j<unique.size();j++){
           if(unique[i].second == unique[j].second && i!=j){
               return false;
           }
       }
       }
      return true;
    }
};

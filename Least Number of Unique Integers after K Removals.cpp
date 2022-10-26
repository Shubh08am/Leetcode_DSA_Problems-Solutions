class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
     unordered_map<int,int>mp;
        vector<pair<int,int>>vp;
        for(auto&it:arr) mp[it]++;
    
        for(auto&it:mp) {
           vp.push_back({it.second,it.first});
        }
        int curr=0;
        int val=0;
        sort(vp.begin(),vp.end()) ; 
        for(int i=0;i<vp.size();i++){
          curr+=vp[i].first;
            if(curr>k){
                break;
            }
            val++;
        }
        int ans = vp.size()-val;
      //  cout<<val<<endl;
      //  cout<<vp[0].first<<" "<<vp[0].second;
        
        return ans;
    }
};


class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
   
        map<string,long long  int>mp;
        vector<string>ans,dum;
        vector<vector<string>>res;
        map<string,pair<long long  int,string>>freq;
        map<string,bool>vis;
        
        for(int i=0;i<creators.size();i++){
            mp[creators[i]]+=views[i];
            //if(freq[creators[i]].second>ids[i] and freq[creators[i]].first<views[i] || vis[creators[i]]==0){
            if(freq[creators[i]].first<=views[i] || vis[creators[i]]==0){
               
                if(freq[creators[i]].second>=ids[i] and freq[creators[i]].first==views[i] || freq[creators[i]].first!=views[i] ||vis[creators[i]]==0){
            freq[creators[i]] = {views[i],ids[i]};
                vis[creators[i]]=1;
            }}
        }
 
        
        //find max value from mp first
        long long  int mx = INT_MIN;
        for(auto it:mp){
            mx=max(mx,it.second);
        }
        
        //find all creators with max views sum
                for(auto it:mp){
           if(it.second==mx){
               ans.push_back(it.first);
           }
        }
        
        /*
    
        for(int i=0;i<ans.size();i++){
              //pairing of views and ids of ans
        vector<pair<int,string>>vp;
        
            for(int j=0;j<creators.size();j++){
                if(ans[i]==creators[j]){
                    //than do pairing of views and ids
                    vp.push_back({views[j],ids[j]});
                    
                }
            }
                sort(vp.begin(),vp.end());
              reverse(vp.begin(),vp.end());
      
                //find lexicographically smallers id --> vp[in vp].second
            int max_view = vp[0].first;
            
            for(int l=0;l<vp.size()-1;l++){
                if(vp[l].first==max_view){
                    //compare lexicographically
                    string curr = vp[l].second;
                    string next = vp[l+1].second;
                    if(curr>next){
                        dum.push_back(next);
                    }
                    else{
                        dum.push_back(curr);
                    }
                }
            }
                
            //vp size is 1
            if(vp.size()==1){
                dum.push_back(vp[0].second);
            }
}
        
        
        //take elements from ans and dum and add in res
        for(int i=0;i<ans.size();i++){
            vector<string>v(2);
                v[0]=ans[i];
                v[1]=dum[i];
            res.push_back(v);
        }
 */
          for(int i=0;i<ans.size();i++){
            vector<string>v(2);
                v[0]=ans[i];
                v[1]=freq[ans[i]].second;
            res.push_back(v);
        }
        
        return res;
    }
};

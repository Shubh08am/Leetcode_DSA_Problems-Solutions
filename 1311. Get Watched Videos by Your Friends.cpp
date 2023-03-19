class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size(), curr_level = 0;
        vector<int>vis(n,0);
        unordered_map<string,int>freq;
        vector<pair<int,string>>results;
        vector<string>ans;
        //do BFS traversal
        queue<int> q;
        q.push(id);

        vis[id] = 1;//start from src as id

        while(!q.empty()){
            if(curr_level++==level) break;
            int sz = q.size();
            while(sz--){ 
                auto node=q.front();
                q.pop();
                 //push friends of id  
                for(auto &it:friends[node]){
                    if(!vis[it]){
                      vis[it] = 1;  
                        q.push(it);
                    }
                }
            }
        }
       
       //Now,q contains all friends at given level see videos watched by them 
       // and store there frequency
        while(!q.empty()){
            auto node=q.front();
            q.pop();

            for(auto &video:watchedVideos[node])
                freq[video]++;
        }
        
        for(auto &it:freq){ 
            int frequency = it.second ; 
            string video = it.first; 
            results.push_back({frequency,video});
        }
      
      //sort on basis of frequency 
        sort(results.begin(),results.end());
   
      //now,take videos watched at that level
        for(auto &it:results){
            ans.push_back(it.second);
        }
        return ans;
    }
};

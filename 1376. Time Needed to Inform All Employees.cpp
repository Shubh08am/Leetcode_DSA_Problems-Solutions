class Solution {
public:
    void dfs(vector<int>& informTime,int headID,int &maxTime,int time,vector<int>adj[]){
         maxTime=max(maxTime,time) ; 

        for(auto&it : adj[headID]){
             dfs(informTime,it,maxTime,time+informTime[headID],adj);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
         vector<int>adj[n] ; 

         for(int i=0;i<n;i++){
          if(manager[i]==-1) continue;
            adj[manager[i]].push_back(i) ; 
         }
        int maxTime=0;
        dfs(informTime,headID,maxTime,0,adj) ; 
        return maxTime;
    }
};

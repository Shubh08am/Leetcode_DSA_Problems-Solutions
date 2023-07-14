class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        map<int,vector<int>>adj;
        int n = routes.size() ; 
        for(int i=0;i<n;i++){
            for(auto&it:routes[i]){
                adj[it].push_back(i);
            }
        }
        //bfs 
        queue<int>q;
        map<int,bool>visited,busVisited;
        q.push(source) ; 
        visited[source]=1;
        int bus=0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int Currcity = q.front() ; 
                q.pop() ; 
                if(Currcity==target){
                    return bus;
                }

                //go to bus of that Currcity and traverse further city 
                for(auto&it:adj[Currcity]){
              //  cout<<Currcity<<" "<<it<<"\n";
                    if(busVisited[it]) continue;
                    busVisited[it]=1;
                    for(auto&x:routes[it]){
                        //now,visit furthet city from that Currcity
                        if(!visited[x]){
                         //   cout<<x<<" ";
                            visited[x]=1;
                            q.push(x);
                        }
                    }
                }
            }
            bus++;
        }
    return -1;
    }
};

class Solution {
public:
bool canVisitAllRooms(vector<vector<int>>&rooms) {

int totalRoom = rooms.size(),amount=0;
set<int>uniqueRoom;

bool check=true;
map<int,bool>visited;
visited[0]=1;//0th room visited first

for(auto it:rooms[0]){
uniqueRoom.insert(it);
}

//see till true 
while(uniqueRoom.size()!=0 and check){
int searchFor = *uniqueRoom.begin();
//to remove tle need to remove element : breaking condition of loop
uniqueRoom.erase(uniqueRoom.begin());
//Already visited room -> no need to visit again
if(visited[searchFor]){
     continue;
}
amount++;
 //marking next room as visited
visited[searchFor]=1;

 //seeing next room keys value            
for(auto it:rooms[searchFor]){

if(visited[it]) {
continue;
}
 uniqueRoom.insert(it);
 }
            
if(amount==totalRoom-1) {
    check=false; break;
}

}
        return (amount==totalRoom-1);
    }
}; 

//METHOD-2 
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //simple bfs or dfs works
        int n = rooms.size();
       vector<int>vis(n,0);
       queue<int>q;
       vis[0]=1;//initially 0th room visited
       q.push(0);//0 push as we start bfs from there
       while(!q.empty()){
           int node = q.front() ; 
            q.pop();

            //see keys at that node
            for(auto it : rooms[node]){
               if(!vis[it]) {
                    q.push(it);
                    vis[it]=1;
            }
        } 
    }

    for(int i=0;i<n;i++){
        if(!vis[i]) {
            return false;
            }
    }
     return true ;
    }
};

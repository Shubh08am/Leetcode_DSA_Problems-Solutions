class disjointSet{
vector<int> rank,parent,size;    
public:
disjointSet(int n){
    rank.resize(n+1,0);
    parent.resize(n+1,0);
    for(int i = 0;i<=n;i++) parent[i] = i;
    size.resize(n+1,1);
}
int findParent(int u){
if( u == parent[u]) return u;
int x = findParent(parent[u]);
parent[u] = x;
return x;
}
void unionbyrank(int u,int v){
int x = findParent(u);
int y = findParent(v);
if(x==y) return;
if(rank[x]>rank[y]) {
    parent[y] = x;
}
else if(rank[y] > rank[x]) parent[x] = y;
else {
    parent[x] = y;
    rank[y]++;
}
}
void unionbysize(int u,int v){
    int x = findParent(u);
    int y = findParent(v);
    if(x == y) return ;
    if(size[x] > size[y]){
        parent[y] = x;
        size[x] += size[y];
    }
    else{
        parent[x] = y;
        size[y]+= size[x]; 
    }
}
void parentize(){
    for(int i = 0;i<parent.size();i++){
        parent[i] = findParent(i);
    }
}
int countComponent(){
    parentize();
    int cnt = 0;
    for(int i = 1;i<parent.size();i++){
         if(parent[i]==i) cnt++;
    }
    return cnt;
}
bool isConnected(int u,int v){
    return findParent(u) == findParent(v);
}
};
bool comp(vector<int> &a,vector<int> &b){
    return a[0] > b[0];
}
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),comp);
        disjointSet alice(n),bob(n);
        int cnt = 0;
        for(auto& it : edges){
            int u = it[1];
            int v = it[2];
            if(it[0] == 3){
               if(alice.isConnected(u,v) && bob.isConnected(u,v)) cnt++;
               else {
                   alice.unionbysize(u,v);
                   bob.unionbysize(u,v);
               }
            }
            else if(it[0] == 2){
                 if(bob.isConnected(u,v)) cnt++;
                 else bob.unionbysize(u,v);
            }
            else{
                 if(alice.isConnected(u,v)) cnt++;
                 else alice.unionbysize(u,v);
            }
        }
        bool ok = true;
         if(alice.countComponent() != 1) ok = false;
        if(bob.countComponent() != 1) ok = false;
        if(!ok) return -1;
        return cnt;  
    }
};

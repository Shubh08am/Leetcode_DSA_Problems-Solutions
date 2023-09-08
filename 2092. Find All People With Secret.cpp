class DSU{
public:
vector<int>parent,rank;
DSU(int n){
    parent.resize(n+1) ; 
    rank.resize(n+1,0) ; 
    for(int i=1;i<=n;i++) {
        parent[i]=i;
    }
}
int findUltimateParent(int node){
    return (node==parent[node])?node:parent[node]=findUltimateParent(parent[node]);
}
void UnionByRank(int u,int v){
    int ulp_u = findUltimateParent(u) ; 
     int ulp_v = findUltimateParent(v) ; 

     if(ulp_u == ulp_v) return ;

     if(rank[ulp_u] > rank[ulp_v]){
         parent[ulp_v] = ulp_u;
     }

     if(rank[ulp_u] < rank[ulp_v]){
         parent[ulp_u] = ulp_v;
     }

     if(rank[ulp_u] == rank[ulp_v]){
         parent[ulp_v] = ulp_u;
         rank[ulp_u]++;
     }
}
};
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // DSU 
        vector<int>ans;
        vector<vector<int>>time[100001];
        for(auto it : meetings){
            time[it[2]].push_back({it[0],it[1]});
        }
        DSU ds(n) ; 
        ds.UnionByRank(0,firstPerson);

        for(int i=0;i<=100000;i++){
            //if at this time = i a person p is linked with 0 i.e p knows the secret 
            vector<int>person; 
            for(auto it : time[i]){
                 ds.UnionByRank(it[0],it[1]);
                 person.push_back(it[0]);
                 person.push_back(it[1]);
            }

            //finding whether this person have connection with 0 
            //if not reset there parent to themself 
            for(auto it : person){
                if(ds.findUltimateParent(it)!=ds.findUltimateParent(0)) ds.parent[it]=it;
            }
        }
        for(int i=0;i<n;i++){
            if(ds.findUltimateParent(i)==ds.findUltimateParent(0))  ans.push_back(i) ; 
        }
    return ans;
    }
};

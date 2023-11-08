class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int win=-1,i=0;
        int indegree[n]; 
        memset(indegree,0,sizeof(indegree));
        for(auto&it:edges){
            indegree[it[1]]++;
        }
        for(auto&it:indegree){
            if(it==0){
                if(win!=-1) return -1;
                win=i;
            }
            i++;
        }
    return win;
    }
}; 

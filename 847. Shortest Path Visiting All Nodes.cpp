/*
https://leetcode.com/problems/shortest-path-visiting-all-nodes/solutions/1800180/c-detailed-explanation-answering-why-of-each-question-dry-run-bfs/

Complexity Analysis
Given N as the number of nodes in the graph:
Time complexity: O(2^N*N*N) 

The total number of possible states is O(2^N*N)  because there are 2^N  possibilities for mask, each of which can be paired with one of N nodes.
At each state, we perform a for loop that loops through all the edges the given node has. In the worst case scenario, every node in the graph is connected to every other node, so this for loop will cost O(N) .
Space complexity:O(2^N*N*N) 
Depending on the implementation, cache will either be the same size as the number of states when it is initialized or it will eventually grow to that size by the end of the algorithm in the worst-case scenario.
*/

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        // mask use for visited 
        int n = graph.size();
        queue<vector<int>>q;
        vector<vector<int>>vis(n,vector<int>(1<<n,0)) ; 

        for(int i=0;i<n;i++){
            int mask = 1<<i ; 
            q.push({i,mask,0}) ; 
            vis[i][(1<<i)]=1;
        }

        while(!q.empty()){
            auto it = q.front() ; 
            q.pop() ; 

            int node = it[0] ; 
            int mask = it[1] ; 
            int pathLen = it[2] ; 

            //all path visited when all bit of mask set 
            if(mask == (1<<n)-1){
                return pathLen;
            }

            for(auto adjNode : graph[node]){
                int newMask = mask | (1<<adjNode) ;
                if(!vis[adjNode][newMask]){
                    vis[adjNode][newMask]=1;
                    q.push({adjNode,newMask,pathLen+1});
                }
            }
        }
    return 0;
    }
};

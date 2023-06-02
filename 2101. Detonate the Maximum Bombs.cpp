class Solution {
public:
    void dfs(int node , vector<vector<int>>&graph,vector<int>&vis,int &bombDetonate){
        vis[node]=1;
        bombDetonate++; 

        for(auto&it : graph[node]){
            if(!vis[it]){
                dfs(it,graph,vis,bombDetonate);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        //T.C = O(N^3) S.C=O(N^2)+O(N)[AUXILLARY STACK SPACE]
        //REACH FROM BOMB1 TO BOMB2 -> INTUTION FOR GRAPH THINKING
        //HOW TO REACH -> USING EDGES 

        //WHEN ONE CIRCLE CENTER LIES INSIDE ANOTHER CIRCLE -> BOMB DETONATE 


        int n=bombs.size() ; 
        vector<vector<int>>graph(n) ; 

        for(int i=0;i<n;i++){
            long x1 = bombs[i][0] , y1 = bombs[i][1] , r1 = bombs[i][2]; 
            for(int j=0;j<n;j++){
                if(i==j) continue;
                 long x2 = bombs[j][0] , y2 = bombs[j][1] , r2 = bombs[j][2]; 

                //DISTANCE BETWEEN TWO CIRCLES
                long disBetTwoCir = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) ; 

                //ONE CIRCLE CENTER LIES INSIDE ANOTHER CIRCLE -> SEE RADIUS [R1] FOR IT 
                if(r1*r1 >= disBetTwoCir){
                    graph[i].push_back(j) ;
                }
            }
        }

            int noOfReachableNode=0 ; 

            for(int i=0;i<n;i++){
                int bombDetonate = 0 ; 
                vector<int>vis(n,0);
                dfs(i,graph,vis,bombDetonate);
                noOfReachableNode=max(noOfReachableNode,bombDetonate);
            }

    return noOfReachableNode;
    }
};

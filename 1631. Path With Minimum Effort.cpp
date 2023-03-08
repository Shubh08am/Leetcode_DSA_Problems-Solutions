class Solution {
public:
    bool isValid(int newRow , int newCol ,int n , int m){
        if(newRow>=0 && newRow<n && newCol>=0 && newCol<m) return 1;
        return 0 ;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        //{diff,ROW,COLUMN} i.e pair of pair 
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    int n = heights.size() , m = heights[0].size() ; 
    vector<vector<int>>dist(n,vector<int>(m,1e9));

    //src distance marked 0 
    dist[0][0]=0; 
    //initially, {0,{0,0}} push in pq  i.e diff = 0 , row=0 , col = 0 
    pq.push({0,{0,0}});
    
    //4 direction traversal 
    vector<int>delRow= {-1,0,+1,0};
    vector<int>delCol= {0,-1,0,+1};

    //Apply, Dijkstra's Algorithm
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int diff = it.first ; 
        int row = it.second.first , col = it.second.second;
       
        //traverse all possible 4 direction i.e up ,right, down , left 
        for(int i=0;i<4;i++){
             int newRow = delRow[i] + row ; 
             int newCol= delCol[i] + col ; 
           
           //check valid 
           if(isValid(newRow,newCol,n,m)){
               //check effort and take maximum of current effort and previous i.e diff  
               // going from heights[row][col] --> heights[newRow][newCol]
               int currEffort = abs(heights[row][col] - heights[newRow][newCol]);
               //take maximum 
               int newEffort = max(currEffort , diff) ; 

               //condition 
               if(newEffort < dist[newRow][newCol]){
                   //update distance 
                   dist[newRow][newCol]=newEffort;
                   //push in pq
                   pq.push({newEffort,{newRow,newCol}});
               }
           }
        }
    }
    return dist[n-1][m-1];
    }
};

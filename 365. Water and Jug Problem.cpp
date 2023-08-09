class Solution {
public:
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        /*
        J1 = 5 J2 = 3 targetCapacity=4 
        // i.e at last kuch aisa hoo j1=5 and j2=2 
        pehle j1 bharo aur j2 mein daalo -> J1=2 j2=3 
        phir j2 empty kro -> j1=2 j2=0
        ab j1 ko j2 mein daalo -> j1=0 j2=2 
        ab j1 bharo -> j1=5 j2=2 
        ab j1 se 1 j2 mein daalo -> j1=4 j2=3 
        4 measure hogya
      */
     
       if(jug1Capacity+jug2Capacity<targetCapacity) return 0;
        int g = gcd(jug1Capacity,jug2Capacity);
        return targetCapacity%g==0;

    // BFS 
    int dx [] ={jug1Capacity,-jug1Capacity,jug2Capacity,-jug2Capacity} ; 
    int total = jug1Capacity + jug2Capacity ;  
    vector<int>vis(total+1,0) ; 
    queue<int>q; 
    q.push(0) ; 
    vis[0] = 1 ; 

    while(!q.empty()){
        int node = q.front() ; 
        q.pop() ; 
        if(node == targetCapacity) return true ; 
        for(int i=0;i<4;i++){
            int adjNode = node + dx[i];
            if(adjNode>=0 && adjNode<=total && !vis[adjNode]){
                vis[adjNode]=1;
                q.push(adjNode);
            }
         }
    }
    return false;
    }
};

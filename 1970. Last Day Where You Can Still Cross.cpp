class Solution {
public:
    bool isValid(int nr,int nc,int row,int col){
        return nr>=0 && nr<row && nc>=0 && nc<col;
    }
    bool canReachLastCell(int mid,int row,int col,vector<vector<int>>& cells){
        vector<pair<int,int>>dirs={{0,-1},{1,0},{-1,0},{0,1}}; 
        queue<pair<int,int>>q;
        vector<vector<int>>visited(row,vector<int>(col,0));

         for(int i=0;i<mid;i++){
            //since,1 based indexing -> -1 to convert to 0 based indexing
            visited[cells[i][0]-1][cells[i][1]-1]=1;
        }

        //PUSH ALL THE POSSIBLE STARTING POINT I.E FIRST ROW ALL LANDS  IN QUEUE 
        for(int i=0;i<col;i++){
            //cout<< visited[0][i] << " ";
            if(visited[0][i]==0){
                q.push({0,i});
                visited[0][i]=1;
            }
        }

        //DO BFS NOW 
        while(!q.empty()){
            int r = q.front().first , c = q.front().second ; 
            q.pop() ; 

            //DESTINATION RREACHED 
            if(row==r+1) return true;
            //DO ALL 4 DIRECTION TRAVERSAL 
            for(auto&it:dirs){
                int nr = r + it.first ;
                int nc = c + it.second ; 

                //MOVE TO VALID CELL WHICH IS NOT WATER
                if(isValid(nr,nc,row,col) && !visited[nr][nc]){
                    visited[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    return false;    
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        //MULTI-SOURCE BFS 
        //BRUTE FORCE -> DO BFS CALL ALL DAY -> O(row*col * row*col)

        //Monotonic graph i.e possible... not-possible... (v pattern) therefore binary search
        //OPTIMZE -> USE BINARY SEARCH ON DAY -> O(row*col * log(row*col))
      

        int start = 0 , end = row*col , lastDay=0; 
        while(start<=end){
            int mid = start + (end-start)/2 ; 
            if(canReachLastCell(mid,row,col,cells)){
                lastDay=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
    return lastDay;
    }
};

class Solution {
public:
    bool isValid(int nr,int nc,int n,int m){
        return nr>=0 && nr<n && nc>=0 && nc<m ;
    }
    bool dfs(int ind,int row,int col,vector<vector<bool>>&vis,vector<vector<char>>& board, string word) {
        int n = board.size() , m = board[0].size() ; 
        if(ind==word.size()) return true;
        int dx[]={0,0,-1,+1} , dy[]={-1,+1,0,0} ; 
        for(int i=0;i<4;i++){
            int nr = row + dx[i] ; 
            int nc = col + dy[i] ; 
            if(isValid(nr,nc,n,m) && !vis[nr][nc] && board[nr][nc]==word[ind]){
                vis[nr][nc]=1;
               if(dfs(ind+1,nr,nc,vis,board,word)) return true;;
                vis[nr][nc]=0;
            }
        }
    return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size() , m = board[0].size() ; 
        vector<vector<bool>>vis(n,vector<bool>(m,false)) ; 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                     vis[i][j]=1;
                    if(dfs(1,i,j,vis,board,word)) return true;
                     vis[i][j]=0;
                }
            }
        }
        return false;
    }
};

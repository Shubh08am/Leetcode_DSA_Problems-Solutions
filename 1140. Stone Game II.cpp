class Solution {
public:
    int solve(int i,int m,bool turn,vector<int>& piles,vector<vector<vector<int>>>&dp) {
        int n=piles.size();
        if(i>=n) return 0;
        int &val=dp[i][m][turn];
        if(val!=-1) return val;

        //if turn=1 Alice goes and maximize the result therefore take result as INT_MIN 
        //if turn=0 Bob goes and minimize the result therefore take result as INT_MAX
        int result = (turn==1?INT_MIN:INT_MAX),stones=0;

        //Go till min of n-i or 2*m 
        for(int x=1;x<=min(n-i,2*m);x++){
            stones+=piles[i+x-1]; //this act as prefix sum 
            //Alice goes -> Next time than bob goes(turn 0) -> update m by max(m,x) here x represents last times no of piles choosen -> update i to i+x as we took x piles 
            if(turn==1){
                result=max(result,stones+solve(i+x,max(m,x),0,piles,dp));
            }
            //Bob goes -> Next time than Alice goes(turn 1) -> update m by max(m,x) here x represents last times no of piles choosen -> update i to i+x as we took x piles 
            else{
                result=min(result,solve(i+x,max(m,x),1,piles,dp));
            }
        }
    return val=result;
    }
    int stoneGameII(vector<int>& piles) {
        //[1,2,3,4,5,100]
        //1 alice  
        //2 bob 
        //3 alice 
        //4,5 bob 
        //100 alice -> Thus, total alice = 104 
    int n=piles.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
    //1 indicates Alice and 2 indicates bob
    return solve(0,1,1,piles,dp);
    }
};

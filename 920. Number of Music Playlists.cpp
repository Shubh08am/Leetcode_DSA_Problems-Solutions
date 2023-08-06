class Solution {
public:
    const int mod = 1e9+7;
    int solve(int songsLen,int uniqueSongListen,int n,int goal,int k,vector<vector<int>>&dp){
        if(songsLen==goal){
            //must listen n songs 
            return uniqueSongListen == n ;
        }
        if(dp[songsLen][uniqueSongListen]!=-1) return dp[songsLen][uniqueSongListen];

        //here new song
        int remSong = n-uniqueSongListen; 
        int take = (1ll*(remSong)%mod*solve(songsLen+1,uniqueSongListen+1,n,goal,k,dp))%mod ;

        //here,old song again
        int remSong2 = max(uniqueSongListen-k,0); 
        int notTake = (1ll*(remSong2)%mod*solve(songsLen+1,uniqueSongListen,n,goal,k,dp))%mod ;

      //  cout<< take+notTake << "\n"; 
        return dp[songsLen][uniqueSongListen] = (take+notTake)%mod ;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        /*
        can repeat a song after k turn only if goal number of songs with n songs being played condition satisfied
         since,total ways -> dp 
         take notTake method  
         states -> one for unique songs and one for length of playlist 
         k turns ke baad bhi choice hain repeat krre ya naa krree 
         */
         vector<vector<int>>dp(goal+1,vector<int>(goal+1,-1));
         return solve(0,0,n,goal,k,dp) ;
    }
};

class AuthenticationManager {
public:
    map<string,int>manage;
    int time;
    AuthenticationManager(int timeToLive) {
        time = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        manage[tokenId] = currentTime + time ; 
    }
    
    void renew(string tokenId, int currentTime) {
        if(!manage.count(tokenId)) return;
        if(manage[tokenId] > currentTime)  manage[tokenId] = currentTime + time ; 
    }
    
    int countUnexpiredTokens(int currentTime) {
        //LINKEDIN OA
        int ans = 0 ;
        for(auto & cnt : manage) {
            ans+=cnt.second>currentTime?1:0;
        }
    return ans;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */

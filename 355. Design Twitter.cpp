class Twitter {
public:
    map<int,set<int>>mp;
    vector<pair<int,int>>vp;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        vp.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>tweet ; 
        //for most recent -> least recent taverse from back
        for(int i=vp.size()-1;i>=0;i--){
            auto it = vp[i];
            if(tweet.size()==10) break;
            else{
                //userId post
                if(it.first==userId) tweet.push_back(it.second);
                //userId followers post
                if(mp[userId].count(it.first)) tweet.push_back(it.second);
            }
        }
    return tweet;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId)  ;
    }
    
    void unfollow(int followerId, int followeeId) {
         mp[followerId].erase(followeeId)  ;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

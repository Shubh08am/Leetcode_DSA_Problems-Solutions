class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        priority_queue<int>pq(piles.begin(),piles.end());
        int alice=0,bob=0;
        bool ok=0;
        while(!pq.empty()){
            if(!ok){
                alice+=pq.top();
                ok=1;
            }
            else if(ok){
                bob+=pq.top();
                ok=0;
            }
            pq.pop();
         }
         return alice>bob;
    }
};

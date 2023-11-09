class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>ans(2); 
        // 0-> not lost match
        // 1-> lost 1 match
        map<int,int>win,loss; 
        for(auto & it : matches){
            loss[it[1]]++;
            win[it[0]]++;
        }
        for(auto&it:win){
            if(!loss[it.first]) ans[0].push_back(it.first);
        }
        for(auto&it:loss){
            if(it.second==1) ans[1].push_back(it.first);
        }
    return ans;
    }
};

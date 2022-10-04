class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
      sort(trainers.begin(),trainers.end(),greater<int>()) ;
      sort(players.begin(),players.end()) ;
        int ans=0;
        int start =  0 ;
        int end = trainers.size()-1;
       
        while(start<players.size() and end>=0){
            if(players[start]<=trainers[end]){
                ans++;
                start++;
            }
             end--;
        }
        return ans;
    }
};

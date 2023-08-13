class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<pair<int,int>>pq; 
        map<int,int>freq;
        for(auto&it:hand) freq[it]++;
        for(auto&it:freq) pq.push({it.first,it.second}) ; 

        while(!pq.empty()){
            int group = groupSize; 
            vector<pair<int,int>>remain ; 
            int prev = pq.top().first+1 ;
             
            while(group--){
               // cout<<pq.top().first<<"\n";
                if(!pq.empty() && prev-1==pq.top().first){
                    prev=pq.top().first;
                    remain.push_back({pq.top().first,pq.top().second-1}) ; 
                    pq.pop();
                }
                else return false;
            }
            for(auto&val:remain) {
             if(val.second>0) pq.push(val);
            }
        } 
    return true;
    }
};

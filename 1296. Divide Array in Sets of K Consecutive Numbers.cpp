class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int,int>freq; 
        priority_queue<pair<int,int>>pq; 
        for(auto&it:nums) freq[it]++;
        for(auto&it:freq) pq.push({it.first,it.second}) ; 

        while(!pq.empty()){
            int prev = pq.top().first+1 ; //for the ending value of sequence start with one more and subtract 1 later .. ex:- prev=7 and prev-1=6 and pq.top().first=6 
            int group = k ;
            vector<pair<int,int>>remain; 

            while(group--){
                if(!pq.empty() && prev-1 == pq.top().first){
                    prev = pq.top().first ; 
                    remain.push_back({pq.top().first,pq.top().second-1}) ; 
                    pq.pop() ;
                }
                else return false;
            }
            for(auto&it:remain){
                if(it.second>0) pq.push(it);
            }
        }
    return true;
    }
};

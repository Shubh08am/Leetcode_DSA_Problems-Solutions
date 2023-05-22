class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<int>pq;
        unordered_map<int,int>mp;
        vector<int>ans;

        for(auto&it:nums) mp[it]++;

        for(auto&it:mp){
             pq.push(it.second);
        }

        while(!pq.empty()){
            if(ans.size()==k) break;
            int freq = pq.top();
            pq.pop();
            for(auto&it:mp){
                if(it.second==freq && find(ans.begin(),ans.end(),it.first)==ans.end()) ans.push_back(it.first);
            }
        }
    return ans;
    }
};

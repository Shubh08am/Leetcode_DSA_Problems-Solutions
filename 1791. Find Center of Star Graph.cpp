class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>freq;
        for(auto it : edges){
            freq[it[0]]++;freq[it[1]]++;
        }
        int maxi=-1,center=0;
        for(auto it:freq){
            if(it.second>maxi){
                maxi=it.second;
                center=it.first;
            }
        }
        return center;
    }
};

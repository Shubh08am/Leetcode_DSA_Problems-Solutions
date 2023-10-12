class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // O((N+M)LOGN) solution -> binary search 
        int n = flowers.size() ; 
        vector<int>start,end,flower;
        for(auto&it:flowers){
            start.push_back(it[0]);
            end.push_back(it[1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        for(auto&it:people){
            int flower_blossom_start = upper_bound(start.begin(),start.end(),it) - start.begin();
            int flower_blossom_end = lower_bound(end.begin(),end.end(),it) - end.begin()  ;
            int curr_flower_blossom = abs(flower_blossom_end - flower_blossom_start) ; 
            flower.push_back(curr_flower_blossom);
        }
    return flower;
    }
};

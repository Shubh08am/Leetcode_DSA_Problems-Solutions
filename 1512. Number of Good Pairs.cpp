class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>freq;
        int pair=0;
        for(auto&it:nums) freq[it]++;
        for(auto[x,y]:freq){
            pair+=(y*(--y))>>1;
        }
        return pair;
    }
};

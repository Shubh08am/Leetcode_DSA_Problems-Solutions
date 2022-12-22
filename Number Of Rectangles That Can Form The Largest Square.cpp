class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
         map<int,int>sideSize;
        int max_len=0;
     for(auto&it:rectangles){
         int lengthOfSide = min(it[0],it[1]) ; 
            max_len=max(max_len,lengthOfSide);
         sideSize[lengthOfSide]++;
     }

        return sideSize[max_len];
    }
};

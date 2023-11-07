class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int curr=0,win=-1,i=0;
        for(auto&it:grid){
            int c = count(it.begin(),it.end(),1) ; 
            if(curr<c){
                curr=c;
                win=i;
            }
            i++;
        }
    return win;
    }
};

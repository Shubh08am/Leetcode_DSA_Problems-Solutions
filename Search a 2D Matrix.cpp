class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        bool f=0;
        vector<int> c;
        for(auto&x : matrix){ 
            for(auto&y:x){ 
        c.push_back(y) ;
        }}
        for(int i=0;i<c.size();i++){
            if(c[i]==target) f=1;
        }
        if(f) return 1;
        
        return 0;
    }
};

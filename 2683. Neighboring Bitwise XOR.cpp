class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        int n =d.size() ; 
        int c=0; 
        for(int i=0;i<n;i++){
            c^=d[i] ; 
        }
          return c==0?true:false ; 
    }
};

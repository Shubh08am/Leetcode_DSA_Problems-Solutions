class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    vector<int>v ; 
        for(int i=0 ; i<matrix.size();i++){
            for(int j=0 ; j<matrix.size();j++){
    v.push_back(matrix[i][j]);         
           
                }}
       
     sort(v.begin(),v.end());


        return v[k-1] ;
    }
};

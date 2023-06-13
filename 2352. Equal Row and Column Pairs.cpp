class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
       //Hashing 
       map<vector<int>,int>freq;
       int n = grid.size() , m = grid[0].size() , pairs=0; 

       for(int i=0;i<n;i++){
           vector<int>track=grid[i] ; 
           freq[track]++;
       } 

     // for(auto&x:freq) cout<<x.second<<" ";
     //  cout<<"\n";

       for(int j=0;j<m;j++){
           vector<int>track(n);
           for(int i=0;i<n;i++){
               track[i]=grid[i][j];
           }
        //   for(auto&it:track) cout<<it<<" ";
        //   cout<<"\n";
           pairs+=freq[track];
       }
       return pairs;
    }
};

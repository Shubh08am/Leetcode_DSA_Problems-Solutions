class Solution {
public:
     int countNegatives(vector<vector<int>>& grid) {
        int negativeNo=0;
        int n = grid.size();

        for(int i=0;i<n;i++){ 
          int start=0,ans=0;
          int end = grid[i].size()-1;
           while(start<=end){
                          int mid  = start+(end-start)/2;
                if(grid[i][mid]<0) end = mid-1;
               else if(grid[i][mid]>=0) start = mid+1;
            //    cout<<i<<" "<<mid<<" ";
            }
          // cout<<"\n"; 
            negativeNo+=(grid[i].size()-start);
        }
    return negativeNo;
    }
};

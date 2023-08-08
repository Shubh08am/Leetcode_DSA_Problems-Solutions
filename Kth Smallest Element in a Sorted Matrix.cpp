class Solution {
public:
    bool isPossible(vector<vector<int>>& matrix,int mid, int k){
        int cnt = 0 ,  n = matrix.size() , m = matrix[0].size(); 

        //bs on every row
         for(int i=0;i<m;i++){
            // cout<<pos<<" ";
            int pos = n-1;//last value of each column considered highest and comparison started
             while(pos>=0 && matrix[i][pos]>mid){
                 pos--;
             }
             cnt = cnt+pos+1;
         }
    //cout<<mid<<" "<<cnt<<"\n";
    return cnt>=k;
    }
     bool isPossible2(vector<vector<int>>& matrix,int mid, int k){
        int cnt = 0 ,  n = matrix.size() , m = matrix[0].size(); 

        //bs on every row
         for(int i=0;i<m;i++){
             int pos = upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin() ; 
             cnt = cnt+pos;
         }
    //cout<<mid<<" "<<cnt<<"\n";
    return cnt>=k;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size() , m = matrix[0].size() ;
        int low = matrix[0][0] , high = matrix[n-1][m-1] ;
        while(low<=high){
            int mid = low + (high-low)/2 ; 

            if(isPossible2(matrix,mid,k)){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
    return low;
    }
};

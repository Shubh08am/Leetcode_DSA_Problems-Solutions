class Solution {
public:
    bool isPossible(int n,int m,int k,int mid){
        int smallCnt = 0 ; 
        // go to every column and see how many are smaller than mid 
        //or go to every row and see how many are smaller than mid 
        for(int i=1;i<=n;i++){
            smallCnt+=min(mid/i,m) ;//for every column case 
            //smallCnt+=min(mid/i,n) ;//for every row case -> loop till m
        }
      //  cout<<mid<<" "<<smallCnt<<"\n";
        return smallCnt<k ;
    }
    int findKthNumber(int m, int n, int k) {
       int low = 1 , high = m*n ; 
       while(low<=high){
           int mid = low + (high-low)/2 ; 
          //  cout<<low<<" "<<high<<" "<<mid<<"\n";
           if(isPossible(n,m,k,mid)){
               low=mid+1;
           }
           else high=mid-1;
       }
    return low;
    }
};

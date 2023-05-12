class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        bool increasing=true , decreasing=false ; 
        bool found=false , found2=false ;
        int i=0;
         while(i<n-1){
            bool flg=1,ok=1;
            if(found && arr[i]<arr[i+1])  return false; 
             while(i<n-1 && !decreasing && !found && arr[i]<arr[i+1]){
               //    cout<<i<<" inc " ;
                i++;found2=true;flg=0;
            }
             while(i<n-1  && increasing && found2 && arr[i]>arr[i+1]){
               //  cout<<i<<" dec " ;
                i++;found=true;decreasing=true;ok=0;
            }
            if(flg && ok) return false; 
          } 
          return increasing && decreasing && found && found2 ;  
    }
};

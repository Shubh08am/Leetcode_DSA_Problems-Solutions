class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        //prefix sum and than last value must be divisible by 3 
         int n = arr.size(), can = 1;
        for(int i=0;i<n-1;i++){
            arr[i+1]+=arr[i];
         //   cout<<arr[i]<<" ";
        }
       // cout<<arr[n-1]<<"\n";
        if(arr[n-1]%3!=0) return false;
        int partition_Sum =  arr[n-1]/3;
        int start = arr[n-1] - partition_Sum ;  
        for(int i=n-2;i>=0;i--){
            if(arr[i]==start){
            //    cout<<i<<" ";
                can++;
                start-=partition_Sum;
            }
        }
     //   cout<<can;
     return can>=3 ;
    }
};

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int x = logs.size() ; 
           int ans=logs[0][1] , res=logs[0][0];
       // vector<int>v;
        for(int i=0;i<x-1;i++){
            int val1 = logs[i][1];
             int val2 = logs[i+1][1];
            
            int diff = val2 - val1 ;
           // cout<<diff<<" ";
            if(ans<diff){
                ans=diff;
                res=logs[i+1][0];
            }
            else if(ans==diff){
                ans=diff;
                res=min(res,logs[i+1][0]);
            }
           // cout<<endl;
          //   cout<<ans<<" ";
        }
     
      
        
        return res;
    }
};

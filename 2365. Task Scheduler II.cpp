class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long ans=0 ; 
        int n = tasks.size();
         unordered_map<int,long>days;
        for(int i=0;i<n;i++){
            //visit first time no break 
           if(days[tasks[i]]==0){
                ans++;
                days[tasks[i]] = ans+space+1 ;
           }
            //already visited 
            else{    ans++;
                    if(ans< days[tasks[i]]){
                     ans =  days[tasks[i]] ;
                 } 
                    days[tasks[i]]= ans+space+1 ;
            }
        }
        return ans; 
    }
};

class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        int n = processorTime.size() , m=4*n ; 
        sort(tasks.rbegin(),tasks.rend()) ; 
        sort(processorTime.begin(),processorTime.end()) ; 
        int ans=0 , c = 0 ,j=0; 
        for(int i=0;i<n;i++){
            int a=0,k=0;
            while(j<m && k<=3){
               a = max (a,processorTime[i]+tasks[j]) ;
                j++;k++;
            }
            ans=max(ans,a) ;
        }
    return ans;
    }
};

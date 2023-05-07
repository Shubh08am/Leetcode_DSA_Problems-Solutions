class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        //match cost of each level 
        
        // 2*node --> pow(2,level) vale rahenge 
        int total=0;
        for(int i=n-1;i>=1;i-=2){
            
            if(cost[i-1]>cost[i]){
                total+=cost[i-1]-cost[i];
                cost[i]=cost[i-1];
            }
            else{
                 total+=cost[i]-cost[i-1];
                cost[i-1]=cost[i];
            }
            cost[(i-1)/2]+=cost[i] ; 
        }
        
        return total;
    }
};

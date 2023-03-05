class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = 0 , n = timeSeries.size();
        for(int i=0;i<n-1;i++){ 
           int timeDiff = timeSeries[i+1] - timeSeries[i] ;
           if(timeDiff>duration) total+=duration;
           else if(timeDiff<=duration)total+=timeDiff;
       }
        total+=duration;
        return total ; 
    }
};

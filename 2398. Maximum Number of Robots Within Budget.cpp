class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        //sliding window 
        long long i=0,j=0,n=chargeTimes.size(),sum=0;
        int maxLen=0;
        multiset<int,greater<int>>maxHeap;

        while(j<n){
            sum+=runningCosts[j];
            maxHeap.insert(chargeTimes[j]);
            
            int k = j-i+1 ; //window length 

            //since, maxHeap max at top 
            long long condition = *maxHeap.begin() + k*sum;
         //  cout<<k<<" "<<condition<<"\n";
            //Remove calculation for i -> when condition violated 
            while(!maxHeap.empty() && condition > budget){
                //reduce sum from ith position 
                sum-=runningCosts[i];
                //remove from maxHeap also as of no use now
                auto it = maxHeap.find(chargeTimes[i]);
              maxHeap.erase(it);
              i++;
              k=j-i+1;
            if(!maxHeap.empty())  condition = *maxHeap.begin() + k*sum ; //update condition as i updated
            }
            k=j-i+1;//window length updated
            maxLen=max(maxLen,k);
            j++;
        }
    return maxLen;
    }
};

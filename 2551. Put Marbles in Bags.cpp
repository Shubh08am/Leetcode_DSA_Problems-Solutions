class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
       vector<int>prefix;
       int n = weights.size() ; 
       //first and last value always in partition 
       //look for more k-1 partition 
       //adjacent value form a pair contributing to sum 
       //maximize and minimize it 
       for(int i=0;i<n-1;i++){
           prefix.push_back(weights[i]+weights[i+1]);
       }
       priority_queue<int>maxHeap ; 
       priority_queue<int,vector<int>,greater<int>>minHeap;

       for(int i=0;i<n-1;i++){
           maxHeap.push(prefix[i]) ;  minHeap.push(prefix[i]) ; 
           if(maxHeap.size()>k-1) maxHeap.pop() ;
           if(minHeap.size()>k-1) minHeap.pop() ;
       }
        long minVal=0,maxVal=0;
       //take first k-1 pairs min value and last k-1 pairs max value 
       while(!maxHeap.empty() && !minHeap.empty()){
        //   cout<<maxHeap.top()<<" ";
           minVal+=minHeap.top();   minHeap.pop() ;
           maxVal+=maxHeap.top();   maxHeap.pop() ;
       }
       //maxVal obatined from minHeap 
       //minVal obatined from maxHeap 
    return minVal-maxVal;
    }
};

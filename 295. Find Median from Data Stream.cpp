class MedianFinder {
public:
    priority_queue<int>maxHeap; 
    priority_queue<int,vector<int>,greater<int>>minHeap; 
    MedianFinder() {
        
    }
    void balanceHeap(){
        if(maxHeap.size() > minHeap.size() && maxHeap.size() - minHeap.size() > 1){
            minHeap.push(maxHeap.top()) ; 
            maxHeap.pop();
        }
        else if(maxHeap.size() < minHeap.size() && minHeap.size() - maxHeap.size() == 1){
            maxHeap.push(minHeap.top()) ; 
            minHeap.pop();
        }
    }
    void addNum(int num) {
       if(maxHeap.empty()) {
           maxHeap.push(num) ;
         }
       else if(maxHeap.top()>=num) {
           maxHeap.push(num) ;
         }
       else {
           minHeap.push(num) ;
        }
        balanceHeap();
    }
    
    double findMedian() {
        //Always more element in maxHeap in case of odd number of element implementation done
     //   cout<<maxHeap.size()<<" "<<minHeap.size() <<"\n";
        if(maxHeap.size() > minHeap.size()) {
           //  cout<<maxHeap.top()<<"\n";
            return maxHeap.top() ; 
            }
        else {
         //   cout<<maxHeap.top()<<" "<<minHeap.top()<<"\n";
            return (maxHeap.top() + minHeap.top())/2.0 ;
            }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

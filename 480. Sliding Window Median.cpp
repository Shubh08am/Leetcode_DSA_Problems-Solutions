class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        //median data stream concept 
        multiset<long long>minHeap;
        multiset<long long,greater<long long>>maxHeap ; 
        int n = nums.size() ; 
        vector<double>ans;

        for(int i=0;i<n;i++){
            if(maxHeap.empty() || *maxHeap.begin()>=nums[i]){
                maxHeap.insert(nums[i]);
            }
            else{
                minHeap.insert(nums[i]);
            }
            int mah = maxHeap.size();
            int mih = minHeap.size();

            if(mah-mih>1){
                auto it = maxHeap.begin() ; 
                minHeap.insert(*it) ; 
                maxHeap.erase(maxHeap.find(*it));
            }
            else if(mih>mah){
                auto it = minHeap.begin() ; 
                maxHeap.insert(*it) ; 
                minHeap.erase(minHeap.find(*it));
            }
            if(i>=k-1){
                double res = 0.0 ; 
                if(k&1){
                    res = *maxHeap.begin() ;
                }
                else{
                    res = (*maxHeap.begin()   + *minHeap.begin())/2.0 ;
                }
                ans.push_back(res) ; 
                //removal logic 

                if(maxHeap.find(nums[i-k+1]) != maxHeap.end()){
                    maxHeap.erase(maxHeap.find(nums[i-k+1]));
                }
                else if(minHeap.find(nums[i-k+1]) != minHeap.end()){
                    minHeap.erase(minHeap.find(nums[i-k+1]));
                }
            }
        }
        return ans;
    }
};

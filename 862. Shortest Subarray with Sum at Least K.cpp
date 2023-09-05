class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        // Since negative element sliding window can't be applied directly 
        // Maintain monotonically increasing values 
        // use deque for it 
        // Prefix Sum 
        // when we find sum >= k pop from front in dqueue -> shrink window 
        int j=0,n=nums.size(),minLen=INT_MAX,sum=0; 
        vector<long long>prefix;
        for(auto it : nums) prefix.push_back(it);
        deque<int>dq;
        while(j<n){
            if(j>0){
                prefix[j]+=prefix[j-1];
            }
            if(prefix[j]>=k){
                minLen=min(minLen,j+1) ; 
            }
            //Shrink the window logic 
            while(!dq.empty() && prefix[j]-prefix[dq.front()] >= k){
                minLen=min(minLen,j-dq.front()) ;
                dq.pop_front();
            }
            //maintaining monotonically increasing values in deque 
            while(!dq.empty() && prefix[dq.back()]>prefix[j]){
                //cout<< prefix[j] << " ";
                dq.pop_back();
            }
            dq.push_back(j);
        j++;
        }
    return minLen==INT_MAX?-1:minLen;
    }
};

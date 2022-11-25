class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int>result;
        multiset<int>s;
        
        for(int i=0; i<k-1; i++){
           s.insert(nums[i]);
        } 
        
        for(int i=k-1; i<nums.size(); i++){
            s.insert(nums[i]);
            auto it = s.end();
            it--;
           result.push_back(*it);
            
        s.erase(s.find(nums[i-k+1]));
        }
        return result;    
    }
};

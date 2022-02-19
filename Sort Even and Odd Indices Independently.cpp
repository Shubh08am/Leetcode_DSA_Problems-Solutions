class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> o , e , m(nums.size());
        int y = nums.size();
        
        for(int i=0;i<y;i=i+2){
            e.push_back(nums[i]); 
        }
          for(int i=1;i<nums.size();i=i+2){
            o.push_back(nums[i]);
        }
        
        sort(o.begin(), o.end(), greater<int>());
        sort(e.begin(), e.end());
        
         for(int i=1;i<y;i=i+2){
            m[i] = o[i/2];
    
        }
          for(int i=0;i<y;i=i+2){
            m[i] = e[i/2];
            
        }
        
        return m ;
    }
};

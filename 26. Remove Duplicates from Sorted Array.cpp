class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
 
        vector<int>l;
        unordered_map<int, int> m;
      //  l.push_back(nums[0]);
        
    int i = 0 ;
            while(i < nums.size())
        {
            if (m[nums[i]] == 0) l.push_back(nums[i]);
            m[nums[i]]++;
            i++;
        }
        
        nums = l;
        return nums.size();
        
       
    }
};

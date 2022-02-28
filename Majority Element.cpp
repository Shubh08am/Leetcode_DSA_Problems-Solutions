class Solution {

public:

    int majorityElement(vector<int>& nums) {

     unordered_map<int, int> m;

    for(auto i : nums ) { 

        m[i]++;

    

        

        if(m[i] > nums.size() / 2) return i;

    }     

    

return 0;

        

        

    }

};

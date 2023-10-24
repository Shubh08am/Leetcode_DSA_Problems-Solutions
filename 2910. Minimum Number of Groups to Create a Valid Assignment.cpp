class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        int n = nums.size() , maxVal = 0;
        map<int,int> m; 
        for(auto & it: nums) m[it]++;
        vector<int>occ;
        for(auto &it:m) occ.push_back(it.second);
        for(auto it : m) maxVal=max(maxVal,it.second);
        
        for(int size = maxVal; size>=1; size--){
            bool found = true;
            for(auto it:m){
                int rem = it.second%size;
                int quot = it.second/size;
                
                if(rem<size-1){
                    int b = size-1-rem;
                    if(quot>=b) rem = size-1;
                }
                if(rem>0 && rem<size-1) found = false;
            }
            if(found){ 
                int ans = 0; 
                for(auto it: m){ 
                    int freq = it.second; 
                    int rem= it.second%size; 
                    ans += (freq/size); 
                    if(rem > 0) ans++; 
                } 
                return ans; 
            }
        } 
        return -1; 
    }
};

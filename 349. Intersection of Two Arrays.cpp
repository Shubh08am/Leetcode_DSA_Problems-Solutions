class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s(nums1.begin(),nums1.end()) ; 
        vector<int>ans;
        for(auto it : nums2){
            if(s.count(it)){
                ans.push_back(it);
                s.erase(it);
            }
        } 
    return ans;
    }
};

Approach I :-
    
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int m;
        sort(nums.begin() , nums.end());
        for(int i=1 ; i<nums.size();i++)
        {
            if(nums[i]==nums[i-1]) 
                m= nums[i];
        }
        return m;
    }
}; 

Approach II :-
    
    class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans=0;
        map<int,int>s;
        for(int i=0;i<nums.size();i++){
s[nums[i]]++;
        }
        
        for(auto it:s){
            if(it.second>1){
               ans= it.first;
                break;
            }
        }
        return ans;
    }
};

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n=nums.size(); 
        set<int>s;
        for(int i=0;i<n;i++){
            //remove calculation if window size cross 
            if(i>indexDiff) s.erase(nums[i-indexDiff-1]) ; 
/*
[1,14,23,45,56,2,3]
indexDiff=1 and valuediff=10
key concept :-
thus,for 23 -> 23-10=13 than 13 lower bound 14 at index=1 ->true
*/
            int key = nums[i]-valueDiff; 
            //auto pos = lower_bound(s.begin(),s.end(),key); //gives tle
            auto pos = s.lower_bound(key); 
            if(pos!=s.end() && (*pos-nums[i])<=valueDiff) return true;
            s.insert(nums[i]);
        }
    return false;
    }
};

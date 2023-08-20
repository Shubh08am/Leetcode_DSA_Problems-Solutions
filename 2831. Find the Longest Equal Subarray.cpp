class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        //variable sized sliding window
        int n = nums.size() ; 
        unordered_map<int,int>freq; 
        int maxLen=0,i=0,j=0,mx=0;
        while(j<n){
            //in a window consider max frequency one and compare with window size 
            freq[nums[j]]++;
            mx = max(mx,freq[nums[j]]) ;
            
            //deletion = window size - max freq one 
            //no of deletion should be less than k 
            //remove calculation for i
            if((j-i+1 - mx) > k ){
                freq[nums[i]]--;
                if(freq[nums[i]]==0) freq.erase(nums[i]);
                i++;
            }
            maxLen=max(maxLen, mx);
           j++;     
        }
        return maxLen ;
    }
};

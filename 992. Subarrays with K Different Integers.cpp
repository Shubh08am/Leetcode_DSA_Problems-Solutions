class Solution {
public:
    int slidingWindow(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size(),cnt=0;
        unordered_map<int,int>freq; 
        while(j<n){
            freq[nums[j]]++; 
            if(freq.size()>k){
                while(freq.size()>k){
                    freq[nums[i]]--;
                    if(freq[nums[i]]==0) freq.erase(nums[i]) ;
                    i++;
                }
            }
        cnt+=j-i+1;
        //cout<<i<<" "<<j<<" "<<cnt<<"\n";
        j++;
        }
    //cout<<k<<" "<<cnt<<"\n";
    return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // ATMOST K ELEMENT - ATMOST K-1 ELEMENT = EXACTLY K ELEMENT 
        return slidingWindow(nums,k) - slidingWindow(nums,k-1) ;
    }
};

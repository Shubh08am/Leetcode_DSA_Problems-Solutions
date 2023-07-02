class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0 , n=nums.size() ; 
        map<int,int>mp;
        int i=0,j=0;
        while(j<n){
            mp[nums[j]]++;
            //max-min <=2 
            //remove calculation for i when max-min>2 
            int minElem = mp.begin()->first ;
            int maxElem = mp.rbegin()->first ;
            int diff = maxElem - minElem ;
            while(diff>2){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
                minElem = mp.begin()->first ;
                maxElem = mp.rbegin()->first ;
                diff = maxElem - minElem;
            }
            ans+=j-i+1;
            j++;
        }
    return ans;
    }
};

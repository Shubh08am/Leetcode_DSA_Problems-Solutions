class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int>ans;
        unordered_map<int,int>freq;
        
        //till k-2 only as we hit first window for k-1 and than check for answer
        for(int i=0;i<k-1;i++){
          freq[nums[i]]++;  
        }
        int i=k-1;
        
        while(i<n){
            freq[nums[i]]++;
            
            //take in answer now as well 
            int curr=0;
            for(int j=-50;j<=-1;j++){
                curr+=freq[j];
                //x negative integer as well 
                if(curr>=x) {ans.push_back(j);break;}
            }
            if(curr<x) ans.push_back(0);
            
            //now,remove when going to next window
            freq[nums[i-k+1]]--;
            i++;
        }
        
        return ans;
    }
};


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //variable size sliding window 
        //in a window no more than k zeros
        int n=nums.size();
        int maxLen=0,i=0,j=0;
        int zero=0;
        while(j<n){
   
         if(nums[j]==0){
            zero++;
        }

        if(zero>k){
        //    cout<<i<<" "<<j<<" "<<maxLen<<"\n";
            //remove calculation for i 
            while(zero>k){
              if(nums[i]==0)  zero--; //decrease no. of zero in window
                i++;
            }
        } 
            int windowLen = j-i+1;
            maxLen=max(maxLen,windowLen);
            j++;
        }
        
        return maxLen;
    }
};

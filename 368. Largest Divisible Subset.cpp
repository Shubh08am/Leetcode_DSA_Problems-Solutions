class Solution {
public:
    //gives Length only Using Recursion Time Complexity: O(2^N) Space Complexity: O(N) 
    int LIS(int ind,int prev_ind,vector<int>&nums){
        int n=nums.size();
        if(ind==n) return 0;
        
        int take = INT_MIN;
        if(prev_ind==-1 || nums[ind]%nums[prev_ind]==0){
            take=1+LIS(ind+1,ind,nums);
        }
        int notTake=0+LIS(ind+1,prev_ind,nums);

        return max(take,notTake);
    }
    //Time Complexity: O(N*N)+O(N)[for backtracking in worst case]+O(NLOGN)[for sorting] Space Complexity: O(2*N)
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //LIS VARIATION 
        sort(nums.begin(),nums.end());
     //   int length = LIS(0,-1,nums); 
     //   cout<< length <<"\n" ;
         int n=nums.size();
         vector<int>dp(n+1,1),hash(n);//hash stores prev ind of elements  
        int maxi=1 , lastIndex=0;

        for(int ind=0;ind<n;ind++){
            hash[ind]=ind;
            for(int prev_ind=0;prev_ind<ind;prev_ind++){
                    //can this element be taken in subsequence check 
                    //As, we have sorted nums -> nums[prev_ind]%nums[ind]==0 -> this condition is always false 
                    //as nums[ind]>nums[prev_ind] after sorting
                    //and when nums[ind]==nums[prev_ind] -> this will be already handle by nums[ind]%nums[prev_ind]==0
                   if(nums[ind]%nums[prev_ind]==0 && 1+dp[prev_ind]>dp[ind]){
                       dp[ind]=1+dp[prev_ind];
                       hash[ind]=prev_ind;
                   }
            }
            //Now,checking for largest element of subsequence i.e last element of LIS and its index 
            //Check it here or after loops end separately 
         /*   if(dp[ind]>maxi){
                maxi=dp[ind];
                lastIndex=ind;
            }
        */
        }
    //     for(int i=0;i<n;i++) cout<<i<<" "<<dp[i]<<"\n";
     //When Check for largest element of subsequence after loops end separately 
      
      for(int ind=0;ind<n;ind++){
             if(dp[ind]>maxi){
                maxi=dp[ind];
                lastIndex=ind;
            }
        }

       vector<int>div;
       div.push_back(nums[lastIndex]); 

       //Now,backtracking logic applied in hash 
       while(hash[lastIndex]!=lastIndex){
           lastIndex=hash[lastIndex];
           div.push_back(nums[lastIndex]); 
       }
       //subsequence stored in reverse order[as we started from largest element to smallest]in div now reverse it 
       reverse(div.begin(),div.end());
       return div;
    }
};

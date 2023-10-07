class Solution {
public:
    int minOperations(vector<int>& nums) {
        // MIN OPERATION = TOTAL LENGTH - LARGEST VALID PART 
       set<int>s(nums.begin(),nums.end()) ;
        int n = s.size(),total=nums.size();
        vector<int>curr; 
        for(auto it : s) curr.push_back(it) ; 
        int i=0,j=0,maxValidLen=0; 
        while(j<n){
        //remove calculation for i 
        while(curr[j]-curr[i] > total-1) i++;
        maxValidLen=max(maxValidLen,j-i+1); 
     //   cout<< maxValidLen << " ";   
        j++;
        }
    return total-maxValidLen;
    }
};

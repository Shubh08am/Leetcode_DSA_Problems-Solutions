class Solution {
public:
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b) ;
    }
    bool gcdOne(vector<int>&nums){
        bool flag=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            int curr = nums[i] ; 
            for(int j=i+1;j<n;j++){
                //[6,10,15] -> multiples times gcd can be taken 
                curr = gcd(curr,nums[j]);
                if(curr==1){
                    flag=1;
                    break;
                }
            }
        }
        return flag;
    }
    int countOfSubarray(vector<int>&nums){
        int n=nums.size();
        int m=1e9;
        for(int i=0;i<n-1;i++){
            int curr = nums[i] ; 
            for(int j=i+1;j<n;j++){
                //[6,10,15] -> multiples times gcd can be taken 
                curr = gcd(curr,nums[j]);
                if(curr==1){
                    m=min(m,j-i-1); 
                 }
            }
        }
        return m;
    }
    int minOperations(vector<int>& nums) {
        //all even ans = -1 
        //else pick one odd and one even once and change to 1 and for rest left pick 1 
        int even=0,n=nums.size(),one=0,odd=0;
        for(auto&val:nums){
            even+=(val%2==0);
           if(val!=1) odd+=(val%2==1) ;
            one+=(val==1);
        }
        if(even==n) return -1;
        if(one>0) return n-one; 
        
        int left = n-one; 
        // [5,10] -> -1 as well 
        //find gcd pair of 1 
        int possible= gcdOne(nums);
        
        
        if(!possible) return -1;
        
        //replace all sub-array with gcd and count total operation needed 
        //as nums[i],nums[i+1] changed to gcd
        
      //  cout<< countOfSubarray(nums) <<"\n" ; 
        return n+countOfSubarray(nums);
    }
};

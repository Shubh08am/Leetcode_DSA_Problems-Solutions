class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
    // see start pos of 0 and end every time and  take in count len*(len+1)/2
    long long len = 0 , zero=0;
           
    for(int i=0;i<nums.size();i++){  
        if(nums[i]==0) {
           zero++;
        }
        else{
            len+=(1LL*zero*(zero+1))/2 ; 
        //    cout<<len<<" ";
            //update zero to 0 
            zero=0;
        }
    }
   // cout<<zero<<"\n";
    len+=(1LL*zero*(zero+1))/2 ; //remaining 0 in last 
    return len;  
    }
};

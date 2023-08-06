class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // min ko remove krna hain 
        // tho maximum segment jiska sum = totalSum-x 
        //ho usko rehnedo baaki ko htado 
        // agar koi bhi segment na hoo jiska sum totalSum-x hoo than notPossible to reduce x to 0
        // answer = n - largest window whose sum is totalSum-x 

        int totalSum = 0 , n=nums.size() , i=0,j=0,len=0; 
        for(auto&it:nums){
            totalSum+=it;
        }
        int target = totalSum-x , sum=0; 
        //sabko hii htana pdega nums se to make x 0
        if(target==0) return n;
        //not possible
        if(target<0) return -1;
        while(j<n){
            sum+=nums[j];
            if(sum>target){
                while(sum>target){
                    sum-=nums[i++];
                }
            }
            if(sum==target){
                len=max(len,j-i+1);
                cout<<sum<<" "<<len<<"\n";
            }
            j++;
        }
    return len==0?-1:n-len;
    }
};

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int a=0 , n=nums.size() ; 
        for(int i=0;i<n-1;i++){
            int f=0,l=0;
            for(int j=i;j<n-1;j++){
                if(f==0 && nums[j+1]-nums[j]==1) {f=1;l++;}
                else if(f && nums[j+1]-nums[j]==-1) {f=0; l++;}
                else break;
            }
           if(l>0) a=max(a,l+1);
        }
        return  a==0?-1:a;
    }
};

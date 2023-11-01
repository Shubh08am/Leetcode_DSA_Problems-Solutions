class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int a=0;
        for(int i=0;i<32;i++){
            int b=0,c=(1<<i); 
            for(auto x : nums){
                if(x&c) b++;
            }
            if(b>=k){
                a=(a|c);
            }
        }
        return a;
    }
};

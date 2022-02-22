class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int i,cnt=0;
        int n = nums.size();
        for( i=0 ; i<n ; i++){
        for(int j=n-1 ; j>i ; --j){
                if( (nums[i]==nums[j]) && (i*j)%k==0 ) 
                    cnt++;
            }
        }
        return cnt;
    }
};

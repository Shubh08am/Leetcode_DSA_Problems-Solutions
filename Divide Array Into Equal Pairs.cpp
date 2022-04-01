class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int cnt = 1 ; 
        sort(nums.begin(),nums.end());
        vector<int> v ;
   /*     for ( int i = 1 ; i<nums.size();i++){
            if(nums[i]==nums[i-1] ) cnt++;
            
            else if ( nums[i]!=nums[i-1]) { v.push_back(cnt); }
        }
        */
        while(cnt < nums.size() ){
    if(nums[cnt]!=nums[cnt-1]) return 0; 
            
            cnt+=2;
        }
return true ;
    }
};

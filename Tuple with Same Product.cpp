class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
       int cnt=0;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int value = nums[i]*nums[j];
                m[value]++;
        }
        }
        
        for(auto&it:m){
            if(it.second >1){
            cnt+=8*((it.second)*(--it.second))/2;
            }
        }
        return cnt;
    }
};

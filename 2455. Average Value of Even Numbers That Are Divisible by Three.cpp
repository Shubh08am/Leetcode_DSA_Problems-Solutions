class Solution {
public:
    int averageValue(vector<int>& nums) {
        vector<int>v;
        int sum=0,ans;
        for(auto i:nums){
            if(!(i&1) and i%3==0){
                v.push_back(i);
                sum+=i;
            }
        }
      if(v.size()==0) return 0;
       else ans=sum/v.size();
        return ans;
    }
};

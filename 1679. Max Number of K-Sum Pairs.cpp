class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int ans=0 , rem=0;
        for(auto&it : nums) freq[it]++; 

        for(auto&it : nums){ 
          if(freq[it]>0)   { 
            freq[it]--; 
             rem = k-it ; 
            if(freq[rem]>0 ) {
            //     cout<<it<<" "<<rem<<"\n";
           //   cout<<i<<"\n";
                ans++;
                freq[rem]-=1; 
         //       cout<<freq[it]<<" "<<freq[rem]<<"\n";
                }
            }
        }
        return ans;
    }
};

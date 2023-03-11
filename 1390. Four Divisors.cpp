class Solution {
public:
    map<int,vector<int>>mp;
    //total number of divisor
void number_of_divisor(){ 
     vector<int>v; 
     for(int j=6;j<=100000;j++){ 
       for(int i=1;i*i<=j;i++){
      if(j%i==0){ 
          if(v.size()>4) break;
          if(j/i!=i){
              v.push_back(j/i);
              v.push_back(i);
          }      
          else{
               v.push_back(i);
          }
      }
  }
  mp[j]=v;
  v.clear();
  } 
 }
    int sumFourDivisors(vector<int>& nums) {
        long long int  ans = 0;
         number_of_divisor();
        for(int i=0;i<nums.size();i++){
               if(mp[nums[i]].size()==4){ 
              //     cout<<nums[i]<<" ";
                  for(auto &it : mp[nums[i]] ) ans+=it;
               }
        }
        return ans;
    }
};

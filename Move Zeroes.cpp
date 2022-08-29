class Solution {
public:
    void moveZeroes(vector<int>& nums) { 
        vector<int>v(nums.size()); 
  int e=nums.size();
    v=nums ;
      int o=0 ;  
  nums.clear(); 
      for(int i=0 ; i<e ; i++){
    if(v[i]!=0){
        nums.push_back(v[i]) ;}
          else o++;
          
          }
       while(o--){
           nums.push_back(0);
           }
        
      
    }
};

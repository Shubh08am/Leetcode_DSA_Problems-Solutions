class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
 int n=nums.size();
 bool flg = 0;
 int first=INT_MAX , second = INT_MAX;
 if(n<3) return 0;
 else{
for (auto it : nums){
    int third = it;
       if (second< third){
       	return true ;
      }
 if (first < third) {
    	second=min (second,third);
     }
 first = min (first,third);
     }
 }
return 0;                                                                   
       
    }
};

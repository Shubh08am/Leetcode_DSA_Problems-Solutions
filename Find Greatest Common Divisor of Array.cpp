class Solution {
public:
    int findGCD(vector<int>& nums) {
int small = *min_element(nums.begin(),nums.end());
int large = *max_element(nums.begin(),nums.end());
int mx =1;
for(int i=2;i<=large;i++){
if(small%i==0 and large%i==0){
mx=max(mx,i);	
		}		
}
return mx;       
    }
};

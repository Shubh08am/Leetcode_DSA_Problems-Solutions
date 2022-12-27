class Solution {
public:
    int gcd(int a ,int b)
{
    if(b==0) return a;
    return gcd (b,a%b );
    }
    
    int subarrayGCD(vector<int>& nums, int k) {
int cnt = 0 , n=nums.size() ;
        
for(int i=0;i<n;i++){ 
   int x=nums[i];
for(int j=i;j<n;j++){ 
   
x = gcd(nums[j],x);


	if(x==k) cnt++;	
	 
  //  cout<<cnt<<endl;
}}
return cnt;        
    }
};

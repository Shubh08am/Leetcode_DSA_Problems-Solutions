class Solution {
public: 
    int reverse(int n){
int rev=0;
while(n){
rev=rev*10+n%10;
n/=10;		
		}	
return rev;	
    } 
    
    int countDistinctIntegers(vector<int>& nums) {
 set<int>s;
for(auto&i:nums){
	s.insert(i);
	int reversed_no = reverse(i);
	s.insert(reversed_no);	
}

return s.size();       
    }
};

class Solution {
public:
    string largestGoodInteger(string num) {
 
string ans; int res = INT_MIN ;
for(int i=0;i<num.size()-2;i++){	
if(num[i]==num[i+1] && num[i+1]==num[i+2]){
int val = num[i]-'0' ; 
    res = max(res,val);
}
} 
  int cnt = 3 ; 
    while(cnt--)ans+=to_string(res);
if(res==INT_MIN) return "";

return ans;	
	       
    }
};

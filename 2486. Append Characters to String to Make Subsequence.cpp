class Solution {
public:
    int appendCharacters(string s, string t) {
int si=0,tj=0;
int n=s.size();
int m = t.size();

while(si<n && tj<m){
	if(s[si]==t[tj]){
		tj++;
	}
	si++;	
}


if(si==n){
return m-tj;	
}
	return 0;
       
    }
};

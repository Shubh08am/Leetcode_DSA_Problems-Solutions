class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
int  n = s.size();
int i=0 , j=0;

while(i<n and j<spaces.size()){
		if(spaces[j]!=i){
	   ans+=s[i];
        }
            
            
   else {ans+=' '; ans+=s[i] ; j++;}
		
    
		i++;
}
while(i<n) { ans+=s[i];i++;}
return ans;
    }
};

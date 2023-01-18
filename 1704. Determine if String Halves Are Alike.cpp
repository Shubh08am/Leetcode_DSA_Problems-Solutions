class Solution {
public:

bool halvesAreAlike(string s) {
 int i=0 , n=s.size(), vow=0;
 while(i<n/2){
     char ch = s[i];
if(ch=='a' || ch=='A' || ch=='e'|| ch=='E'|| ch=='i' || ch=='I'|| ch=='o' || ch=='O' || ch=='u'|| ch=='U') vow++;  
  i++;
 }

 while(i<n){ char ch = s[i];
if(ch=='a' || ch=='A' || ch=='e'|| ch=='E'|| ch=='i' || ch=='I'|| ch=='o' || ch=='O' || ch=='u'|| ch=='U') vow--;  
  i++;
 }

return vow==0;        
    }
};

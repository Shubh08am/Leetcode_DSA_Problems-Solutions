class Solution {

public:

    bool strongPasswordCheckerII(string password) {

        

int n = password.size();

string s = password;

int c=0,cc=0,cp=0,p=0,ic=0,ci=0;

bool f=1;

for(int i = 0 ; i<n ; i++){

	

	if(s[i]>=65 && s[i]<=90) c++;

	

		if(s[i]>=97 && s[i]<=122) cc++;

	

	

		if(n>=8) cp++;

	

		if(s[i]>= 48 && s[i]<=57) p++;

	

		if(s[i]=='!' || s[i]=='@' || s[i]=='#' || s[i]=='$' || s[i]=='%' || s[i]=='^' || s[i]=='&' || s[i]=='*' || s[i]=='(' || s[i]==')' || s[i]=='-' || s[i]=='+') ic++;

	

}

for(int i = 0 ; i<n-1 ; i++){

	

	if(s[i]==s[i+1])  {f=0; break;}}

	

	

if(c>=1 and cc>=1 and cp>=1 and p>=1 and ic>=1 and f==1) {

	return true;

}

else return false;

    }

};

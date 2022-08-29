Approach I:-
class Solution {
public:
    int firstUniqChar(string s) {
       int i, n = s.size() ;
        int A[26]={0};

        for(i=0;i<n;i++)

 	        A[s[i]-97]++;           
      
      for(i=0;i<n;i++)

        {

            if(A[s[i]-97]==1)

                return i;

        }

        return -1;

    }

}; 

Approach II:-
    
    class Solution {
public:
    int firstUniqChar(string s) {
        map<int,int>mp ; 
        for(int i=0;i<s.size();i++){

	mp[s[i]]++;

} 

for(int i=0;i<s.size();i++){

	if(mp[s[i]] == 1) {

		return i ;

	}

}  
        return -1 ;
    }
};

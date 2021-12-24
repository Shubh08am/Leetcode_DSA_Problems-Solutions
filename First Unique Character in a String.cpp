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

class Solution {
public:
    int minimumMoves(string s) {
    
           int res=0;
          int i=0,n=s.size();
        while(i<n)
        {
            if(s[i]=='X')
            {
                i=i+3;
                res++;
            }
            else
            {
                i++;
            }
        }
       
      
return res;
    }
};

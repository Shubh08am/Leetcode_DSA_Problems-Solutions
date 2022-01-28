class Solution {
public:
    string removeDuplicates(string s) {

        int a=0 , n= s.size();
        
        while(a<n)
        {
            if(s[a]==s[a+1])
            {
                s.erase(a,2);
                
                if(a!=0)
                    a--;
            }
            else
                a++;
        }
      return s;
      
      
    }
};

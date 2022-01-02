class Solution {
public:
    bool checkString(string s) {
        
        // 1st approach - t.c (O(n*n))
      /*  
        for ( int i=0;i<s.size() ; i++) 
        {
            if(s[i] == 'b')
            {
                        for ( int j=i+1;j<s.size() ; j++) 
        {
            if(s[j] == 'a')
            
               return 0 ;
                        }     
        }
            }
            return 1;
        
        */ 
        
        //2nd approach- t.c (O(nlogn))
     /*   
        string m = s;
        sort(m.begin() , m.end());
        if ( s==m)
            return true;
       
        return false;
     */
        
        //3rd Approach - t.c (O(n))
        
        bool countb= 0 ;
        
        for ( int i=0;i<s.size() ; i++) 
        {
            if(s[i] == 'a' && countb== 1)
                return 0;
            
            if(s[i] == 'b' )
                countb= 1;
        }
        return 1;
    }
};

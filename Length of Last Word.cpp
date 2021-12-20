class Solution {
  public:    
  int lengthOfLastWord(string s) {          
    string m ;
    int count = 0;   
    int ans = 0 ;
    // Ist Approach :-
    /*for (int i = 0; i < s.length(); i++)    
    {   if (s[i] != ' ')   
    {    count++;
    ans = count;    
    }            
    else           
    {                
    count = 0;                          
    // if (len < count)                                                     
    }   ans = max(ans , count) ;       
    }*/            
    // IInd Approach :- (using ASCII codes)
    for ( int i = 0 ; i<s.size() ; i++) {	 
      if ( s[i]== 32 )  { 
        count = 0 ;}    
      if ( s[i] != 32 )  {   
        count++ ;   
        ans = count ;       
      }  
      ans = max ( ans , count ) ;      
    }       
    return ans;    
  }           
};

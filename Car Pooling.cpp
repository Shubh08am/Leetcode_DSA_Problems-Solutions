class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<int> pass(1002 , 0);
            
            for( int i = 0 ; i<trips.size() ; i++)
            {
                int cnt = trips[i][0];
                int from = trips[i][1];
                int to = trips[i][2];
               
                // now add cnt to pass , at from position.
                //than substract cnt from pass , at to position.
          // ARRAY MANIPULATION TECHNIQUE      
                pass[from] = pass[from] + cnt;  
                pass[to] = pass[to] - cnt;
                    
            }  
              
        
            // prefix sums    
                for (int i = 1 ; i<=1000 ; i++)
                {
                 pass[i] = pass[i] + pass[i-1] ;            
                }
        
        //Now, iterating through pass and seeing whether it follow its capacity limits. If yes return true else return false.
          
                for (int i = 0 ; i<=1000 ; i++)
                {
               if  ( pass[i] > capacity)
                   return false ;
                 
                }
     
    return true; 
            
    }
};

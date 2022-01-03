class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        // method 1 using two array
        // tc- O(n+n) = O(n)
    /*    
        vector<int> trustedbypeople(n+1 , 0);
        vector<int> trusting(n+1 , 0);
        
        for(auto& x : trust )
        {
            trustedbypeople[x[1]]++;
            trusting[x[0]]++;
            
        }
        
        for ( int i =1 ; i<= n ; i++)
        {
            if ( trustedbypeople[i] == n-1 &&  trusting[i]==0)
                return i;
        }
        return -1 ;
        
        */
        
        // 2nd method using one array
        // t.c O(n)
        
        vector<int> trusting(n+1 , 0);
        
        for(auto& x : trust )
        {
            trusting[x[1]]++;
            trusting[x[0]]--;
            
        }
        
        for ( int i =1 ; i<= n ; i++)
        {
            if ( trusting[i] == n-1 )
                return i;
        }
        return -1 ;
        
    }
};

class Solution {
public:
    
    /*  SIEVE OF ERATOSTHENES */ 
    /* T.C -> O(n*log(log(n)))*/
    
    int countPrimes(int n) {
        // cnt -> To count number of prime number in range i.e less than n
     int cnt=0;
        // Creating a vector of type boolean with n+1 size , in which all elements are initialize as True.
        vector<bool> p(n+1,true);
        
        // Since, 0 and 1 are not prime number discarding them.
            p[0] = p[1]=false;
     
        // Initially Assuming all values to be as a prime number
        for(int i = 2 ; i< n ; i++)
        {
            if(p[i])    // First time 2 considered as a prime no.
                cnt++; // Incrementing count of prime no.
          
            // Now, contradicting our assumptions that all no. were prime 
            /* First deleting all no. which are multiple of 2 and so on continuing */
        
            for(int j = 2*i ; j<n ; j=j+i)
            {
                p[j]=false; 
                // p[j]=0 --> Or this line both are correct
            }
        }
        return cnt; // Giving back total count of prime no. in range which are less than n.
    }
};

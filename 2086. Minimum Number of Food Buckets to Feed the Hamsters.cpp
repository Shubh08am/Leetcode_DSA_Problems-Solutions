class Solution {
public:
    int minimumBuckets(string hamsters) {
        int n = hamsters.size() , ans = 0;
        vector<int>h;
        //not possible to feed hamsters only if they seat consecutively && no . in adjaent position 
        if(n==1 && hamsters[0]=='H') return -1;
         if(n==1 && hamsters[0]=='.') return 0;
        if((n>=2 && (hamsters[0]=='H' && hamsters[1]=='H') || (hamsters[n-2]=='H' && hamsters[n-1]=='H'))) return -1;

        for(int i=1;i<n-2;i++){ 
            // in beteen 1 to n-2 3H together
            if(hamsters[i]=='H' && hamsters[i+1]=='H' && hamsters[i+2]=='H') return -1;
        }
         for(int i=0;i<n;i++){ 
          if(hamsters[i]=='H')  h.push_back(i) ;
        } 
        if(h.size()==0) return 0; 

        for(int i=0;i<n;i++){
            if(hamsters[i]=='H'){
                if(i+1<n and hamsters[i+1]=='.'){
                    ans++;
                    i+=2;
                }
              else  if(i-1>=0 and hamsters[i-1]=='.'){
                    ans++;
                }
            }
        }
        return ans;
    }
};

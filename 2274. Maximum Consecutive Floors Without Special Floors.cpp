class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int n=special.size();
        int block = lower_bound(special.begin(),special.end(),bottom)-special.begin();
        int prev_Block=0,diff=0;

        if(block<n) {
            diff=special[block]-bottom;
            prev_Block=special[block];
        }

        for(int i=block;i<n;i++){
         int furtherBlock = 
         upper_bound(special.begin(),special.end(),prev_Block)-special.begin();

          if(furtherBlock<n) {
              diff=max(diff,special[furtherBlock]-prev_Block-1) ;
              prev_Block=special[furtherBlock];
          }
        }
        diff=max(diff,top-special[n-1]) ;
        
        return diff;
    }
};

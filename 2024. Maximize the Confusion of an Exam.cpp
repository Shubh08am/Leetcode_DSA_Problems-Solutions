class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i=0,j=0,n=answerKey.size(),len=0,t=0,f=0;
        //TC -> O(N)
        //see for max true and max false in single iteration  
        while(j<n){ 
                f+=answerKey[j]=='F';
                t+=answerKey[j]=='T';
                //remove calculation for i logic -> shrink logic
                while(i<j && min(f,t)>k){
                    f-=answerKey[i]=='F' ;
                    t-=answerKey[i]=='T' ;
                    i++;
                }
            //    cout<<i<<" "<<j<<" "<<j-i+1<<"\n";
            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};

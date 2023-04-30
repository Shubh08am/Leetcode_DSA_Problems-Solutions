class Solution {
public:
    int addMinimum(string word) {
        int c=0,n=word.size(); 
        if(n==1) return 2;
        int pos=-1;
         int r = 0;
        for(int i=0;i<n;i++){
            //for a
            if(word[i]=='a'){
                if(i+1<n && word[i+1]=='b'){
                    if(i+2<n && word[i+2]=='c'){
                        i+=2;
                    }
                    //ab_
                    else{
                        i++;
                        r++;
                        }
                }
                
                //ac
                else if(i+1<n && word[i+1]=='c'){
                    i++;
                    r+=1;
                }
                //aa
                else{
                    r+=2;
                }
            }
            
            //for b
            else if(word[i]=='b'){
                //bc -> insert a
                if(i+1<n && word[i+1]=='c'){
                    r+=1;
                    i++;
                }
                else{
                    r+=2;
                }
            }
            else if(word[i]=='c'){
                r+=2;
            }
        }
        return r;
     }
};
 

class Solution {
public:
    string addStrings(string X, string Y) {
         int i = X.size()-1;
        int j = Y.size()-1;
        
        // res string holds final ans
        string res="";
        string val="";
        // carry -> ith and jth pos sum if greater than 9 --> take it in carry
        int carry=0;
        int sum=0;
        
        // this goes till i and j>=0 -> ex. 25 , 23 || 2500 , 23 --> till 00, 23
        while(i>=0 && j>=0){
            
        
        //sum stores sum of ith and jth pos and if any carry is there
         sum=(X[i]-'0')+(Y[j]-'0')+carry;
        
        //val is pushed in res -> 5+6+0=11  --> 11%10 = 1
        
         val = to_string(sum%10) ; 
         
         // update res with val       
        res=val+res;
        
        // update carry
        carry = sum/10;
        
        // go to one index left (from right)
        i--;j--;
        }
        
        
      // 2500 and 23 case  --> here i>=0 but j<0
        if(i>=0 and j<0){
            while(i>=0){
            sum = (X[i]-'0')+ carry ; 
            val = to_string(sum%10);
            res=val+res;
            carry = sum/10;
            i--;
            }
            
        }
      //23 and 2500 case  --> here j>=0 but i<0
        else if(j>=0 and i<0){
            while(j>=0){
            sum = (Y[j]-'0')+ carry ; 
            val = to_string(sum%10);
            res=val+res;
            carry = sum/10;
            j--;
            }
            
        }
      
      // At last if carry is not 0  
        if(carry!=0){
            res=to_string(carry)+res;
        }
     
    // for cases like 
   /*00000000
000000000 
ans = 0 

00000500
000000000
ans = 500
*/

// if we reached end of res than ans will be 0  as it contain only 0

     int end=0;

             for(int i=0;i<res.size();i++){
            end=i;
            if(res[i]!='0') { break;}
        }
        
        if(end==res.size())  return "0";
     
     // i.e not reached end return substring from end to last position
     
      else  {res=res.substr(end);}


        return res;
        
    }
};

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        //suffix sum 
        int n = shifts.size();
        string result="";
        vector<int>suffix(n);
        suffix[n-1]=shifts[n-1]%26;
        for(int i=n-2;i>=0;i--){
            suffix[i]=(shifts[i]+suffix[i+1])%26;
        }
          for(auto&val:suffix) cout<<val<<" ";

       for(int i=0;i<n;i++){
           if(s[i]=='z'){ 
               if(suffix[i]==0) result+='z';
              else result+=(suffix[i]+'a'-1);
           }
           else {
               if(suffix[i]==0) result+=s[i];
               else{ 
                   int currChar = suffix[i]+s[i] ;
                   int rem =  'z' - s[i] ;
                   int remToAdd = suffix[i]-rem;
                    if(currChar>122){
                       result+=('a'+remToAdd-1);
                   }
                   else result+=(suffix[i]+s[i]);
                   }
               }
       }
        return result;
    }
};

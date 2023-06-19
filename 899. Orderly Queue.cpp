class Solution {
public:
    string isSmaller(string a,string b){
        return a>b?b:a;
    }
    string orderlyQueue(string s, int k) { 
        string res=s; 
        int n = s.size(),i=0;
       if(k>1) {
           //simply give the sorted string 
           //as,we first arrange the smallest letter than move to second smallest so on 
           //thus,building the required lexicographically smallest string 
           sort(s.begin(),s.end());
           return s;
       }
       else if(k==1){
             //position of smallest character
             //aegadg -> adgaeg also see for other combination of string from smallest character -> here, adgaeg
            int pos = min_element(s.begin(),s.end()) - s.begin(); 
            char ch = *min_element(s.begin(),s.end()) ;
            vector<int>positionOfSmallest;
            for(int i=0;i<n;i++){
                if(s[i]==ch) positionOfSmallest.push_back(i);
            } 
          //  cout<<pos;
          //see,all combination of string from ch possible and take the smallest one
          while(i<positionOfSmallest.size()){
              int dum=positionOfSmallest[i];
              int pos = positionOfSmallest[i];
              string ans="";
          //take string from pos to last and than from 0 to pos-1 
          while(true){
             ans+=s[pos];
             pos++;
             if(pos>=n) pos%=n;
             if(pos==dum) break;
         }
         // cout<<ans<<" ";
         res=isSmaller(res,ans);
        i++;
       }
    }
       return res;
    }
};

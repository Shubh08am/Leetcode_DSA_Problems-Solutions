class Solution {
public:
    int lastCharOcc(string s){
        int n=s.size(),cnt=1;
        char ch = s[n-1] ; 
        for(int i=n-2;i>=0;--i){
            if(s[i]==ch) cnt++;
            else break;
        }
      return cnt ;
    }
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int>freq(26,0) ; 
        for(auto&i:s) freq[i-'a']++;
        
        string ans="" ; 
         
        for(int i=25;i>=0;--i){
                if(ans.size()>0 && ans.back()==(char)(97+i) && lastCharOcc(ans)>=repeatLimit) break;
            
            if(freq[i]<=repeatLimit){
                while(freq[i]--) ans+=(char)(97+i) ; 
            }
            else if(freq[i]>repeatLimit){  
                
                int curr = freq[i] ; 
                int lenTaken = 0 ;
                while(lenTaken<repeatLimit) {ans+=(char)(97+i) ; lenTaken++; }
              
            //    cout<<ans<<" "<<freq[i]<<"\n";
                
                freq[i]-=lenTaken;
                if(i==0) break;
                int new_i=i-1; 
                                         
                 while(new_i>0 && freq[new_i]==0 ) new_i--; 
                                  
               if(new_i >=0 && freq[new_i]>0)    {ans+=(char)(97+new_i) ; freq[new_i]--;}
                // cout<<ans<<" "<<freq[i]<<"\n"; 
                i++;
            }
        }
        return ans;
    }
};

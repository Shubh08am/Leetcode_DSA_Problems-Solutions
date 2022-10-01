class Solution {
public:
    int largestInteger(int num) {
 
        string s = to_string(num);
        
        string even="";  // stores all even no.
        string odd="";  // stores all odd no.
        string ans="";  // stores result
        
        //storing odd and even no.
        for(auto&it:s) {
                        if((it-'0') &1) odd+=it;
                        else even+=it;
                       }
        
        // sorting them in descending order
        sort(odd.begin(),odd.end(),greater<int>());
        sort(even.begin(),even.end(),greater<int>());

  // this pointer points at odd and even strings respectively
    int odd_start=0;
    int even_start=0;
        
//Now,iterate through s and if odd number is there replace with largest odd no. and similarly for even no. and move pointer to next position
        for(int i=0;i<s.size();i++){
            if((s[i]-'0')&1){ 
                ans+=odd[odd_start] ;
                odd_start++;
            }
            
            else{
                  ans+=even[even_start] ;
                even_start++;
            }
        }
        // convert ans to string 
        int res = stoi(ans);
        return res;
    }
};

class Solution {
public:
    const int mod = 1e9+7;
    //Approach-1
    int oneFilledSubarray(string s) {
    // see start pos of 1 and end every time and  take in count len*(len+1)/2
    long long int len = 0 , one=0;
           
    for(int i=0;i<s.size();i++){  
        if(s[i]=='1') {
           one++;
        }
        else{
            len+=((one*(one+1))/2)%mod ; 
        //    cout<<len<<" ";
            //update one to 0 
            one=0;
        }
    }
   // cout<<one<<"\n";
    len+=((one*(one+1))/2)%mod ;  //remaining 1 in last 
    return len;  
    }
    int numSub(string s) {
      //  return oneFilledSubarray(s);

      //Approach-2
      long long int len = 0 , one=0;
           
    for(int i=0;i<s.size();i++){  
        if(s[i]=='1') {
           one++;
           len=(len+one)%mod;
        }
        else{
            //update one to 0 
            one=0;
        }
    }
    return len;  
    }
};

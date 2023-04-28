class Solution {
public:
    long long smallestNumber(long long num) {
        bool neg=0;
        if(num<0) {
            num*=-1;
            neg=1;
        }
        if(num==0) return 0;
        string s = to_string(num) ; 
        sort(s.rbegin(),s.rend());
         
         if(neg) return -stoll(s) ; 
        //cout<< stoll(s) ;
        unordered_map<int,int>freq;
        for(auto&val:s) freq[val-'0']++;
        string ans="";
        int ch=-1;
        for(int i=s.size()-1;i>=0;--i){
            if(s[i]!='0'){
                ch=(s[i]-'0');
                break;
            }
        }
        //cout<<freq[ch]<<"\n";
             ans+= (ch+'0');
             freq[ch]--;
 
        for(int i=0;i<10;i++){
                 while(freq[i]>0){
                  //  cout<<i<<"\n";
                ans+=(i+'0');
                freq[i]--;
             }
        }
         return stoll(ans); 
     }
};

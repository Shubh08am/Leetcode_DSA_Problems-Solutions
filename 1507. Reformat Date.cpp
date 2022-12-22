class Solution {
public:
    string reformatDate(string date) {
        int n = date.size() ; 
        string res ="";
        string month ="" , mm="";
        int value=0;
        string monthName[13] = {"0","Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        
        for(int i=n-1;i>=n-4;i--){
            res = date[i]+res;
        }
        res+='-';
        
        for(int i=n-6;i>=n-8;i--){
            month=date[i]+month ;
            for(int i=0;i<13;i++){
                if(monthName[i]==month) {
                    value=i;
                }
            }}
            string ch = to_string(value) ;
            if(value<10){
                ch = '0'+ch;
            }
            
            res+=ch;
            res+='-';
        int v =0;
        bool flg=0;
        
        if(date[0]>='0' and date[0]<='9'){
        v+=(date[0]-'0')*10;
         
        }
        
        if(date[1]>='0' and date[1]<='9'){
        v+=(date[1]-'0');
            flg=1;
        }
        if(!flg) v/=10;
        
      //  cout<<v<<"\n";
        
        string ad = to_string(v);
        if(v<10 ) ad='0'+ad;
        
         res+=ad;
        
        return res;
    }
};

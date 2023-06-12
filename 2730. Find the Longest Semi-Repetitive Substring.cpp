class Solution {
public:
    string form(string &s,int start,int end){
        string news="";
        for(int i=start;i<=end;i++) news+=s[i];
        return news;
    }
    int longestSemiRepetitiveSubstring(string s) {
        int len=1;
        int n=s.size() ; 
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                string news = form(s,i,j);
              //  cout<<news<<" ";
                bool unique=0 , notunique=0;
                 
                for(int x=0;x<news.size()-1;x++){
                    if(unique==0 && news[x]==news[x+1]){
                        unique=1;
                    }
                    else if(unique==1 && news[x]==news[x+1]){
                        notunique=1;
                     
                    }
                 }
                 if(!notunique) len=max(len,(int)news.size());
            }
        }
        return len;
    }
};

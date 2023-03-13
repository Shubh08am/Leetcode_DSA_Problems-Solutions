class Solution {
public:
    string thousandSeparator(int n) {
        string s=  to_string(n) , p=""; 
        int cnt=0;
        reverse(s.begin(),s.end());
        for(auto & it : s){
            p+=it;cnt++;
            if(cnt==3) {
                p+='.' ;
                cnt=0;
                }
        }
        if(p.back()=='.') p.pop_back();
        reverse(p.begin(),p.end());
        return p ; 
    }
};

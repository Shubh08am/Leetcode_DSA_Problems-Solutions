class Solution {
public:
    int countSeniors(vector<string>& d) {
        int n = d.size() , c=0;
        for(int i=0;i<n;i++){
        int a = (d[i][11]-'0')*10+(d[i][12]-'0') ; 
             if(a>60) c++;
      //  cout<<a<<" ";
        }
        return c;
    }
};

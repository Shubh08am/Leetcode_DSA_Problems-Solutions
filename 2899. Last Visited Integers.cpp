class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& w) {
        int n = w.size() , c=0; 
        vector<int>a,b; 
           
        
        for(int i=0;i<n;i++){
           
            if(w[i]=="prev"){
                c+=1;
                 int m = b.size() ; 
                if(m<c) a.push_back(-1);
                else{
                    a.push_back(b[m-c]);
                }
            }
            else  {int it = stoi(w[i]); b.push_back(it);c=0;}
        }
      return a ;
    }
};

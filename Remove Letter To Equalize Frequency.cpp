class Solution {
    private:
        bool ok(map<char,int>&remove){
            set<int>wr ; 
            for(auto&i:remove){
                int val = i.second ; 
                if(val>0) {
                    wr.insert(val);
                }
            }
            int sz = wr.size(); 
            if(sz!=1) return 0;
            return 1;
        }

public:
    bool equalFrequency(string s) {
        map<char,int>m; set<int>wr ;
        
        for(auto&i:s) m[i]++;
        int cnt=0;
        vector<int>v;
        for(auto&it:m){
           v.push_back(it.second);
        }
           sort(v.begin(),v.end());
    int st = v[0] ; int end = v[v.size()-1] ; 
        int r = count(v.begin(),v.end(),st); 
                int re = count(v.begin(),v.end(),1);
        
             for(auto&y:m){
          m[y.first]-=1;
               //check from ok 
                 if(ok(m)==1) return 1;
             m[y.first]+=1;    
        }
        
      
/*
         int w = count(v.begin(),v.end(),end); 
         if(r==v.size() and re==v.size()) return 1 ; 
       
      else  if(r==v.size() || w==v.size() ) return 0 ; 
        else        if(r==v.size()-1 || w==1 ) return 1 ; 
        else        if(w==v.size()-1 || r==1 ) return 1 ; 

        */
        return 0;
    }
};

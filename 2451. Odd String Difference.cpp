class Solution {
public:
    string oddString(vector<string>& words) {
    //    unordered_map<string,vector<pair<int,int>>>mp;
        set<vector<int>>st;
        vector<vector<int>>vp;
         map<vector<int>,int>m , freq;
              
     vector<int>res , v;
        
            for(int i=0;i<words.size();i++){
                for(int j=0;j<words[0].size()-1;j++){ 
                    int diff = words[i][j+1]-words[i][j] ;
                           res.push_back(diff);
                   }
                    freq[res]++; 
                res.clear();
            }
        
            for(auto it : freq){
                    if(it.second==1){
                            v=it.first;} // its vector
                    }
        
            for(int i=0;i<words.size();i++){
                    vector<int>vv; 
                   for(int j=0;j<words[0].size()-1;j++){
                       int diff = words[i][j+1]-words[i][j] ;
                           vv.push_back(diff);
                   }
                   if(vv==v){
                           return words[i] ;
                   }
            }
                
            return words[0] ;
        
    }
};

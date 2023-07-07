class Solution {
public:
    int fillCups(vector<int>& amount) {
        multiset<int>ms; 
        if(amount[0]!=0) ms.insert(amount[0]) ;
        if(amount[1]!=0) ms.insert(amount[1]) ;
        if(amount[2]!=0) ms.insert(amount[2]) ;
        int step=0;
        while(ms.size()!=0){
            auto it = *ms.begin() ; 
            auto itr = *(--ms.end()) ; 
            if(it==0)   ms.erase(ms.find(it)) ; 
            if(itr==0)  ms.erase(ms.find(itr)) ;  
            if(ms.size()==1){
                ms.erase(it) ; 
                if(it>1)  ms.insert(--it);
            }
            else{ 
                ms.erase(ms.find(it)) ;  ms.erase(ms.find(itr)) ; 
                if(it>1)   ms.insert(--it);  if(itr>1) ms.insert(--itr);
            }
        step++;
        }
      return step;
    }
};

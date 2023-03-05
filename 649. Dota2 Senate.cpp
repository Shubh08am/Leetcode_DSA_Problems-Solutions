class Solution {
public:
    string predictPartyVictory(string senate) {
        //first R erases first D and R gets appended to senate 
        //first D erases first R and D gets appended to senate 
        /*
        ex:-senate = RDD 
            senate = DR (first R erases first D and R gets appended to senate )
            senate = D (first D erases first R and D gets appended to senate )    
            Thus, winner is Dire 

        ex:-senate = RDDRDR 
            senate = DRDRR (first R erases first D and R gets appended to senate )
            senate = DRRD (first D erases first R and D gets appended to senate )   
            senate = RDD (first D erases first R and D gets appended to senate ) 
            senate = DR (first R erases first D and R gets appended to senate)
             senate = D (first D erases first R and D gets appended to senate ) 
            Thus, winner is Dire     
       */
       queue<int>r,d; 
       int n = senate.size();
       string winner = "";

       for(int i=0;i<n;i++){
           if(senate[i]=='R') r.push(i);
           else d.push(i);
       }
       while(1){
           if(r.empty()&&!d.empty()) {winner="Dire"; break;}
           if(!r.empty()&&d.empty()){winner="Radiant"; break;}
           int indr = r.front() , indd = d.front();
           r.pop() ; d.pop();
           
           //erase the first position i.e min of indr & indd 
           int toDeleteBy = min(indr,indd) ; 
           //first R erases first D and R gets appended to senate
           if(toDeleteBy==indr){
             //R gets appended to senate at last 
             //i.e pos will be indr+n at this pos R gets appended 
             int appendRAtPos = n+indr; 
             r.push(appendRAtPos);
           }
         //first D erases first R and D gets appended to senate 
           else if(toDeleteBy==indd){
             //D gets appended to senate 
             //i.e pos will be indd+n at this pos D gets appended 
             int appendDAtPos = n+indd; 
             d.push(appendDAtPos);
           }
                  }
        return winner ; 
    }
};

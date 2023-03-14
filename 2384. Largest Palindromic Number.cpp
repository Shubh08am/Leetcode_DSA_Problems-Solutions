class Solution {
public:
    string largestPalindromic(string num) {
        unordered_map<int,int>freq; 
        string start="" , end="" , res=""; 

        //first try to utilize all occurence even no. of times and at start and end initially don't take 0 
       // At,last utilize max no. occuring odd time 

       for(auto&it : num) freq[it-'0']++;

       for(int i=9;i>=0;i--){
           int occur = freq[i] ; 
           int take = occur/2 ; 
            
            if(i==0 && start.size()==0 && end.size()==0) continue ;

            //case for 0 & remaining numbers
            else {
                   int copy = take ; 
                   freq[i]-=(copy*2) ; 
                 while(copy--) start+=to_string(i) ;
                  copy=take ; 
                 while(copy--) end+=to_string(i); 
               }
       }

      //now,take 1 more no. which has occurence left 
     for(int i=9;i>=0;--i){
         int occur = freq[i] ; 
         if(occur>0){
                   start+=to_string(i) ; 
                   break;
            }
     } 
   //  cout<<start<<" "<<end; 
     reverse(end.begin() , end.end()) ; 
    res = start + end ; 
    return res;
    }
};

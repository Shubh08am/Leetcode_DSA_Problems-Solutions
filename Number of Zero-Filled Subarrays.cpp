class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        // see start pos of 0 and end every time and sum of 1 to end-start+1
        int start = 0 ;
        int end = 0 ;
        vector<int>nonzero;
    
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
             nonzero.push_back(i);
            }      
        }
 
    if(nonzero.size()==0) {
          long long int subarray= (1LL*nums.size()*(nums.size()+1))/2;
        return subarray;
    }
    else if(nonzero.size()==1) {
 long long int rem = nums.size()-nonzero[0]-1;
         long long int subarray=0;
        
       if(rem >0)  subarray = (1LL *nonzero[0]*(nonzero[0]+1))/2 + (1LL*rem*(rem+1))/2 ; 
      //else  subarray =  (v[0]*(v[0]+1))/2 ;
        
      return subarray;  
    }
     else{
         
        // for(int i=0;i<nonzero.size();i++){ cout<<nonzero[i]<<" ";}cout<<endl;
             long long int subarray=0;
         vector<int>first;
           for(int i=0;i<nums.size();i++){
            if(nums[i]==0){first.push_back(i);
            }}
             // for(int i=0;i<first.size();i++){ cout<<first[i]<<" ";}cout<<endl;
   
         
         if(nonzero[0]!=0){    
            // cout<<nonzero[0]-first[0]<<endl;
                 subarray+=(1LL*(nonzero[0]-first[0])*((nonzero[0]-first[0])+1))/2 ; 
                // cout<<subarray << endl;
             }
         
          if(nonzero[nonzero.size()-1]!=nums.size()-1){    
                 long long int left = nums.size()-1-nonzero[nonzero.size()-1];
                 subarray+=(1LL*left*(left+1))/2 ; 
                 //cout<<subarray << endl;
             }
         
         for(int i=0;i<nonzero.size()-1;i++){
              long long int rem = nonzero[i+1]-nonzero[i] -1;
                // cout<<rem<<endl;
             if(rem >0) {
                 subarray+=(1LL*rem*(rem+1))/2 ; 
               // cout<<subarray << endl;
             }
         }
         return subarray;
     }   
      return 0;  
    }
};

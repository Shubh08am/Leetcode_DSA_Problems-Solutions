class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
   /*
   sort(nums.begin(),nums.end());
    //    long long int sz = *max_element(nums.begin(),nums.end()) + 2;
        int sz = nums.back() +1 ;
       vector<int>hash(sz+2) ;
        int ans = 0 ;
        int left = 0 ;
        for(int i = 0 ; i<nums.size(); i++){
                 
        hash[nums[i]]++;
        }
    
        for(int i=0 ; i<hash.size() ;i++){
            if(hash[i]%2 == 0)
            {
                ans+=(hash[i]/2);
            }
            
           else if (hash[i]%2 !=0){
                ans+=(hash[i]/2); 
                left+=1 ;
            }}
        
        return {ans,left} ;
     */
        map<int ,int> m;

int ans = 0 , left = 0;

for ( int i=0;i<nums.size();i++){

m[nums[i]]++;	

}

for(auto it : m){

ans+=it.second/2 ;

left+=it.second%2;	

}

return {ans,left};
    }
};

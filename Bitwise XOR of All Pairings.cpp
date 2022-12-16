class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int size_nums1 = nums1.size() ; 
           int size_nums2 = nums2.size() ; 
     
        int first = 0 , second = 0  , xor_value=0;
        for(auto&i:nums1) first=(first^i);
        for(auto&i:nums2) second=(second^i);
        
        //cases
        if((size_nums1&1)  && !(size_nums2&1) ){
            return second ;
        }
                //both even

        else if(!(size_nums1&1)  && !(size_nums2&1) ){
            return 0 ;
        }
        
        else if(!(size_nums1&1)  && (size_nums2&1) ){
            return first ;
        }
        
        //both odd
          else if((size_nums1&1)  && (size_nums2&1) ){
              int res= (first^second);
            return res ;
        }
        
        
        
        return 0;
    }
};


Using XOR Operation Concept to solve:- 

class Solution {

public:

    int singleNumber(vector<int>& nums) {

        

        int i,n ;

    int a = nums[0] ;

        n = nums.size();

        for (i = 1 ; i<n ; i++) 

        {

         a = a ^ nums[i] ;

        }

        return a ;

    }

};

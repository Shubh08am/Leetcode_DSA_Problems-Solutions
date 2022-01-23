class Solution {

public:

    int countElements(vector<int>& nums) {

        

        int m = nums.size(); 

        int cnt=0;

        

        for ( int i=1 ; i<m-1 ; i++) 

        {

        sort(nums.begin() , nums.end() ); 

        if(nums[i] > nums[i-1] && nums[i] < nums[m-1] ) 

            cnt++;  

            

            if ( nums[i] == nums[i+1] && (nums[i] > nums[0] && nums[i] < nums[m-1] ) ) 

                cnt++ ; 

            

        }

        return cnt ;

    }

};

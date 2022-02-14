class Solution {

public:

    int getMinDistance(vector<int>& nums, int target, int start) {

     

// Method 1 :-    

        vector<int>v,a;

        int n = nums.size();

        

        for(int i=0 ; i<n ; i++)

        {

            if(nums[i] == target)

            { v.push_back(i);

        }

        }

        sort(v.begin(),v.end()) ; 

        for(int i = 0 ; i<v.size();i++)

        {

            int m = abs ( v[i] - start );

            a.push_back(m);

        }

        sort ( a.begin(),a.end());

        

        return a[0] ; 

// Method 2 :- 

    int c = INT_MAX; 

        int n = nums.size();

        

        for(int i=0 ; i<n ; i++)

        {

            if(nums[i] == target)

            {  c = min ( c , abs(i- start )) ;

        } 

        }       

        return c ; 

    }

};

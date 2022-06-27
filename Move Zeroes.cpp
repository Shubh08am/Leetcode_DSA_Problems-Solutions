class Solution {

public:

    void moveZeroes(vector<int>& nums) {

  vector<int>v ;

        v=nums; 

        int cnt = 0;

        nums.clear();

        for(int i=0 ; i<v.size();i++){ if(v[i] == 0) cnt++;

                                     } 

for(int i=0 ; i<v.size();i++){

if(v[i]!=0) nums.push_back(v[i]) ;    

}

for(int i=1 ; i<=cnt ; i++){

    

    nums.push_back(0);}

        

    }

};

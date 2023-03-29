class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0 , start = 0 , end=0 , n=nums.size(); 

        for(int i=0;i<n;i++){
            //start the jump 
            int jumpAt = i+nums[i] ;
            start=max(start,jumpAt) ; 

            //after,jump increase the jump and end point when reached end point 
            if(i==end && i!=n-1){
                end=start;
                jump++;
            }
            cout<<start<<" "<<end<<"\n";
        }
    return jump;
    }
};

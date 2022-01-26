class Solution {
public:
    int thirdMax(vector<int>& nums) {
       
         int c =1;
        sort(nums.begin(), nums.end());
        for(int i=nums.size()-2; i>= 0;i--){
                if(nums[i] < nums[i+1]){
                    c++;
            }
            if(c == 3){
                return nums[i];
                break;
            }
        }
        return nums[nums.size()-1];
        
    }
};

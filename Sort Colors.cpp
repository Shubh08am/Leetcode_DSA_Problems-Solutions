class Solution {
public:
    void sortColors(vector<int>& nums) {
                 int o=0,oo=0,ooo=0;
         int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0)
                o++;
            else if(nums[i]==1)
                oo++;
            else if(nums[i]==2)
                ooo++;
        }
// clearing nums  {empty vectors}        
        nums.clear(); 
        
// now, pushing 0 , 1 and than 2         
        for(int i=0;i<o;i++){
            nums.push_back(0);
        }
        
        for(int i=0;i<oo;i++){
            nums.push_back(1);
        }
        for(int i=0;i<ooo;i++){
            nums.push_back(2);
        }
    }
};

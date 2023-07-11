class Solution {
public:
    int maxArea(vector<int>& height) {
        //Two-pointers
        int n = height.size(), start=0,end=n-1,maxAmount=0,amount=0;
        while(start<end){
            if(height[start]<height[end]){
                amount=height[start]*(end-start);
                start++;
            }
            else if(height[start]>=height[end]){
                amount=height[end]*(end-start);
                end--;
            }
            maxAmount=max(maxAmount,amount);
        }
    return maxAmount;
    }
};

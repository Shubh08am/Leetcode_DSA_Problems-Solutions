class Solution {
public:
    bool bs(vector<int>& bobSizes,int search){
        int start=0,end=bobSizes.size()-1;
        while(start<=end){
            int mid = start+(end-start)/2;

            if(bobSizes[mid]==search) return true;
            if(bobSizes[mid]>search) end=mid-1;
            if(bobSizes[mid]<search) start=mid+1;
        }
    return false;
    }
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        //maths+bs 
        int alice=0,bob=0;
        for(auto&it:aliceSizes) alice+=it;
        for(auto&it:bobSizes) bob+=it;

        sort(bobSizes.begin(),bobSizes.end());

        for(int i=0;i<aliceSizes.size();i++){
            //alice-x+y=bob-y+x --> y = (bob-alice+2x)/2
            int search = (bob-alice+2*aliceSizes[i])/2;
            if(bs(bobSizes,search)) return {aliceSizes[i],search};
        }
    return {0,0};
    }
};

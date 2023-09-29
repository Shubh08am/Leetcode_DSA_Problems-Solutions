class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](const int a,const int b){
            //cout<<a<<" "<<b<<"\n";
            //see set bit 
            int isoddNo = (a&1) ; 
            int isEvenNo = (b&1) ; 
            bool whichNo = isoddNo < isEvenNo ;
            return whichNo;
        });
    return nums;
    }
};

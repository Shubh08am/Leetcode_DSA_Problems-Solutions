class Solution {
public:
    int hIndex(vector<int>& citations) {
        int s=0; int n = citations.size();
        int e = citations.size()-1;
        int mid = s+(e-s)/2; int result = 0;
        
        
        while(s<=e){
            
            if(citations[mid]>=n-mid ) {
                result = n-mid;
                e = mid-1; 
            }
            
            else s = mid+1;
    
            mid = s+(e-s)/2;
        }
        return result;
    }
};

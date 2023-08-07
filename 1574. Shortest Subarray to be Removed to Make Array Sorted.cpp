class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        /* 
        ek kaam kro left se pehle largest sorted nikalro 
        aur right se bhi 
        */
        int n = arr.size(), low = 0, high = n-1;
        
        while(low+1 < n and arr[low] <= arr[low+1] )  low++;
        
        //already sorted 
        if(low == n-1) return 0;
        
        while(high > low and  arr[high] >= arr[high-1])  high--;
        
        //ya tho sirf left vala part rkho -> right vala htado -> n-low-1 
        //ya tho sirf right vala part rkho -> left vala htado -> high
        int len = min(n-low-1, high), i = 0, j = high;
        
        //combination i.e kuch oart left se loo aur kuch right se 
        while(i<=low and j<n){
            if( arr[i] <= arr[j] ){
                len=min(len, j-i-1);
           //     cout<<i<<" "<<j<<"\n";
                i++;
            }
            else  j++;
        }
    return len;
    }
};

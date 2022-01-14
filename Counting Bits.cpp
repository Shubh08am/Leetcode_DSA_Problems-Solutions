class Solution {
public:
    vector<int> countBits(int n) {
        vector arr(n + 1 , 0); //define an array of size "n+1" and initialize to zero

    for(int i = 0; i <= n; i++)
        arr[i] = arr[i/2] + i%2;    //for even no. i%2 = 0 and for odd no. i%2 = 1
    
    return arr;
    }
};

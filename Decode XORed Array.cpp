class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int i ;
    vector<int> arr ;
        arr.push_back(first); 
        
    //    arr[0] = first ;
        for(i=0 ; i<encoded.size() ;i++)
        {
            arr.push_back( arr[i] ^ encoded[i]); 

        }
        return arr ; 
    }
};

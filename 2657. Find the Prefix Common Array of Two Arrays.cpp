class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>m,mp;
        int n = A.size();
        vector<int>v(n,0); 
        for(int i=0;i<n;i++){
            m[A[i]]++;
            m[B[i]]++;
            
            if(B[i]!=A[i]){
            if(m[B[i]]==2) {
                v[i]+=1;
            }
            if(m[A[i]]==2) {
                v[i]+=1;
            }
            }
            
            if(B[i]==A[i]){
            if(m[B[i]]==2) {
                v[i]+=1;
            }
            }
            
        }
        for(int i=1;i<n;i++) v[i]+=v[i-1];
        
        return v;
    }
};

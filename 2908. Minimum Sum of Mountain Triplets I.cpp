class Solution {
public:
    int minimumSum(vector<int>& n) {
        int m = n.size() , mn=INT_MAX; 
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                for(int k=j+1;k<m;k++){
                    if(n[i]<n[j] && n[j]>n[k]) mn=min(mn,n[i]+n[j]+n[k]);
                }
            }
        }
        return mn==INT_MAX?-1:mn;
    }
};

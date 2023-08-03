class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size() , candy = 0; 
        vector<int> total(n,1); 
        for(int i=0;i<n-1;i++){
            total[i+1]=((ratings[i]<ratings[i+1] && total[i+1]<=total[i])?total[i]+1:total[i+1]) ; 
        }
        for(int i=n-1;i>=1;i--){
            total[i-1]=((ratings[i-1]>ratings[i] && total[i-1]<=total[i])?total[i]+1:total[i-1]) ; 
        }
        for(int i=0;i<n;i++){
         //  cout<<total[i]<<" ";
            candy+=total[i];
        }
    return candy;
    }
};

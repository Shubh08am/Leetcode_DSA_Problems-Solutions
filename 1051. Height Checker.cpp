class Solution {
public:
    int heightChecker(vector<int>& heights) {
      //why to cry when you can try?
      vector<int>cry=heights;
      sort(cry.begin(),cry.end());
      int Try = 0,n=heights.size();
      for(int i=0;i<n;i++) Try+=cry[i]!=heights[i];
     return Try;
    }
};

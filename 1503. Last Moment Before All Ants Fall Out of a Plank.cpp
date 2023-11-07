class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
      int mx=0;
      for(auto it : left){
          mx=max(mx,it);
      }
      for(auto it : right){
           mx=max(mx,n-it);
      }
      return mx;
    }
};

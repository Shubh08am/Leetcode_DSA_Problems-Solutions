class Solution {
public:
    int maxJump(vector<int>& stones) {
      // jumping at alternate stones is an optimal path
      int jump = stones[1]-stones[0], n = stones.size() ; 
      for(int i=0;i<n-2;i++){
        int diff = stones[i+2]-stones[i];
        jump=max(jump,diff);
      }
    return jump;
    }
};

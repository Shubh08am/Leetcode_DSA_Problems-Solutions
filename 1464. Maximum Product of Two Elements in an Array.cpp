class Solution {
public:
    int maxProduct(vector<int>& nums) {
      //  int n = nums.size();
      //  sort(nums.begin(),nums.end()) ; 
      //  return (--nums[n-1]) * (--nums[n-2]) ; 

        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int a = pq.top();
        pq.pop();
        int b =pq.top();
        return --a * --b;

    }
};

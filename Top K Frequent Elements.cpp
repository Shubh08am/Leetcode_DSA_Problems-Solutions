class cmp{
public:
bool operator()(const pair<int,int>&p1 , const pair<int,int>&p2){
  //when same occurence it will yield smaller number
  //ex:- [1,1,1,2,2,2,3,3,3], k = 2 :- [1,2]
  //on top of pq -> larger element will be there and get popped -> p1.second < p2.second
  //ascending order sorting in pq from bottom to top 
  if(p1.first==p2.first) return p1.second < p2.second ; 

  /* when same occurence it will yield larger number :- [2,3]
   //on top of pq -> smaller element will be there and get popped -> p1.second > p2.second
   //descending order sorting in pq from bottom to top 
   if(p1.first==p2.first) return p1.second > p2.second ; 
  */

  
   //on top of pq -> smaller element will be there and get popped
    //descending order sorting in pq from bottom to top 
  return p1.first > p2.first ; 
}
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      //min-heap using custom comparator 
      priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq; 
      unordered_map<int,int>mp; 
      for(auto it : nums) mp[it]++; 

      for(auto it : mp){
        pq.push({it.second,it.first}); 
        if(pq.size()>k) pq.pop() ;
      }

      vector<int>ans ; 
      while(!pq.empty()){
        ans.push_back(pq.top().second) ; 
        pq.pop() ;
      }
    return ans;
    }
};

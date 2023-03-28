class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
       sort(people.begin(),people.end()) ;
       int i=0,j=people.size()-1,cnt=0;
       while(i<=j){
           if(people[i]+people[j] <= limit) {
               i++;j--;cnt++;
           }
           else if(people[j]>=limit) {
               j--;cnt++;
           }
           else if(people[i]>=limit) {
               i++;cnt++;
           }
           else{
               int mx = max(people[i],people[j]);
               if(mx==people[j]) {j--;cnt++;}
               else {i++;cnt++;}
           }
       }
    return cnt;
    }
};

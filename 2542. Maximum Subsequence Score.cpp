class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        //priority queue 
        int n = nums1.size() ; 
        long long ans=-1e9,sum=0; 
        priority_queue<pair<int,int>>pq; 
        //min-heap 
        priority_queue<int,vector<int>,greater<int>>mh; 
       for(int i=0;i<n;i++){
           pq.push({nums2[i],nums1[i]}) ;
       }

       //REMOVING LEAST VALUE FROM MIN-HEAP I.E TOP ELEMENT 
       //WHEN WE HAVE CHOOSEN K ELEMENTS 
        
      for(int i=0;i<n;i++){
          //PUSH VALUE IM MIN-HEAP AND INCREASE THE SUM 
        //  cout<<pq.top().first<<" "<<pq.top().second<<"\n";
           sum+=pq.top().second; 
           mh.push(pq.top().second) ; //MIN-HEAP STORES nums1[i]
          
          //WHEN K ELEMENTS IN MIN-HEAP COMPUTE THE RESULT 
          if(mh.size()==k){
         //   cout<<"MINI  " << mh.top() <<" " <<pq.top().first << "\n" ; 
              ans=max(ans,sum*pq.top().first) ; 

            //REMOVE TOP ELEMENT FROM MIN-HEAP 
            sum-=mh.top(); 
            mh.pop() ; 
          }
           pq.pop();
      }
        return ans; 
    }
};

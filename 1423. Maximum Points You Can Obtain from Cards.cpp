class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // since, I want max sum of length k 
        //my target is to reduce element in orginal array to be minimum 
        //of length total Length - k 
        //i.e find min sum of subarray of length = total Length - k  
       // and subtract from total sum 
       int i=0,j=0,n=cardPoints.size(),totalSum=0,minSum=INT_MAX,sum=0;

       for(auto&val:cardPoints) totalSum+=val;
       int len = n-k ; 
       while(j<n){
           sum+=cardPoints[j] ; 
           if(j-i+1>len){
               sum-=cardPoints[i++];
           }
           if(j-i+1 == len){
               minSum = min(minSum,sum) ; 
           }
           j++;
       }
       return totalSum-minSum;
    }
};

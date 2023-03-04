class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int max_len = 0 , cost=0,k=0; 
        int i=0,j=0,n=s.size(); 
    //    while(k<n) {cout<<abs(s[k]-t[k])<<" "; k++;}
   //     cout<<"\n";
        while(j<n){
            cost+=abs(s[j]-t[j]) ; 
            if(maxCost>=cost){
             max_len = max(max_len,j-i+1); 
        //     cout<<i<<" "<<j<<"\n";
                    }
           else if(maxCost<cost){
                while(cost>maxCost){
                    cost-=abs(s[i]-t[i]) ; 
                     i++;
                }
            }
            j++;
        }
        return max_len;
    }
};

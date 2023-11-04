class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        int ans=0;
        /*
        x1^x2 + y1^y2 = k 
        x1^x2 + y1^y2 = x + k-x 
        x1^x2= x 
        y1^y2= k-x 
        
        x2^x = x1 
        y2^(k-x) = y1 
        */
        map<pair<int,int>,int>mp;
        for(auto &it : coordinates){
             int x2=it[0] , y2=it[1] ;
            for(int i=0;i<=k;i++){
                int x = i , y=k-i; 
              //   cout<<x<<" "<<x2<<"\n";
             //    cout<<y<<" "<<y2<<"\n";
                if(mp.count({x2^x,y2^y}))  ans+=mp[{x2^x,y2^y}];
            }
            mp[{x2,y2}]++;
        }
    return ans;
    }
};

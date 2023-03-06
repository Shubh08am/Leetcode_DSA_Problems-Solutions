class Solution {
public: 
    double distance(int xi , int yi , int xj , int yj){
       int x = abs(xj-xi) , y = abs(yj-yi) ;
       double dis = sqrt(x*x + y*y);
       return dis ; 
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        // brute force
        int ans=0,n=points.size();
       unordered_map<double,int>count;
        for(int i=0;i<n;i++){ 
            int xi = points[i][0] , yi = points[i][1];
            for(int j=0;j<n;j++){
                   if(i!=j){
                      int xj = points[j][0] , yj = points[j][1];
                      double dist = distance(xi,yi,xj,yj);
                      count[dist]++;
                   }
            }
            for(auto it : count) {
            //    cout<<i<<" "<<it.first<<" "<<it.second<<"\n";
                if(it.second>0)
                ans+=it.second*(it.second-1);
            }
        //    cout<<"ans -> "<<ans<<"\n";
            count.clear();
        }
        return ans;
    }
};

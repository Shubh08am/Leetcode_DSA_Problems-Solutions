class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        //binary search 
        vector<vector<int>>P(101);
        vector<int>ans;
        for(auto&coordinate : rectangles){
            int Y = coordinate[1];
            int X = coordinate[0];
            P[Y].push_back(X);
        }
        for(int i=1;i<=100;i++){
            sort(P[i].begin(),P[i].end()) ;
        }
        for(auto&coordinate : points){
            int Y = coordinate[1];
            int X = coordinate[0];
            int count=0;
            //find point greater than or equal to Y in P 
            for(int i=Y;i<=100;i++){
                //compare X now 
                int howMuch = 0;
               // cout<<X<<"\n";
               /* for(auto  x : P[i]){
                    cout<<x<<" ";
                }
                cout<<"\n";
                */
                if(P[i].size()>0){
                howMuch=lower_bound(P[i].begin(),P[i].end(),X)-P[i].begin();
                //cout<<howMuch<<" "<<X<<"\n";
                count+=P[i].size()-howMuch;
                }
            }
            ans.push_back(count);
        }
    return ans;
    }
};

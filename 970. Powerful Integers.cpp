class Solution {
public: 
vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int>s;
        for(int i=0;i<=19;i++){
           for(int j=0;j<=19;j++){
             if(pow(x,i) + pow(y,j)<=bound) {
            //    cout<<pow(x,i) + pow(y,j)<<" ";
                s.insert(pow(x,i) + pow(y,j));
            }
        } 
        }
       vector<int>ans(s.begin(),s.end()); //declare and assign together all value from set to vector
        return ans;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       //search for next greater element 
       //use stack concept of NGE 
       vector<pair<int,int>>vp;
        int n = temperatures.size() ;
       vector<int>ans(n);
       stack<pair<int,int>>s;
       for(int i=0;i<n;i++){
           vp.push_back({i,temperatures[i]});
       } 

    for (int i = n - 1; i >= 0; i--){
        //pop till next greater element or stack gets empty
        
        while (!s.empty() && s.top().second <= temperatures[i]){
           // cout<<s.top().second<<"second ";
            s.pop();
        }
        cout<<"\n";
        //stack is empty means there  is no element on right which is greater than the current element
       // if not empty then the next greater element is on top of stack
        if (s.empty()){
         ans[i]=0;
        }        
        else{
          //  cout<<s.top().first<<"first ";
        int val = s.top().first - i ;
        ans[i]=val;
        }         
         s.push({i,temperatures[i]});
    }       

 return ans;
    }
};

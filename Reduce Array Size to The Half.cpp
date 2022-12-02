class Solution {
public:
    int minSetSize(vector<int>& arr) {
  int n=arr.size();
  int m=n;
  int cnt = 0;
  vector<pair<int,int>>vp;
  unordered_map<int,int>mp;
  for(auto&it:arr) mp[it]++;


  for(auto&it:mp){
  	vp.push_back({it.second,it.first});
      }

      sort(vp.begin(),vp.end());
      reverse(vp.begin(),vp.end());

      for(auto&it:vp){
      	if(n>m/2){
          		n-=it.first;
                  		cnt++;
                          			}
                                      		else {  break;}						
                                              }

                                              return cnt;      
    }
};

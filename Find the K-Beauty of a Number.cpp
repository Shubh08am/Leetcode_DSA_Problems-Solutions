class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int cnt= 0; 
        string s = to_string(num);
  for(int i=0;i<=s.size()-k;i++){

      int m=stoi(s.substr(i,k)); 
     // cout<<m<<endl; 
      if(m!=0 and num%m==0) cnt++;
  }
        return cnt;
    }
};

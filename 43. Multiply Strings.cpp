class Solution {
public:
    string multiply(string num1, string num2) {
       // vector<int>v,a ; 
        int n = num1.size();
        int m = num2.size();
  if(num1=="0" || num2=="0") return "0";
        
//         for(int i=0;i<n;i++){
//             int mm = num1[i]-'0' ; 
//             v.push_back(mm);
            
// }
        
//           for(int i=0;i<m;i++){
//             int ii = num2[i]-'0' ; 
//             a.push_back(ii);
            
// } 
//         n-=1;
//         m-=1;
        
//         long long int sum = 0 ; 
//         long long int sm = 0 ; 
        
//           for(int i=0;i<v.size();i++){
//            sum += (pow(10,n)*v[i]) ; 
//             n-=1;
            
// }
        
//           for(int i=0;i<a.size();i++){
//            sm += (pow(10,m)*a[i]) ; 
//             m-=1;
            
// }
        
//         long long int ans = (sum*sm*1LL) ; 
//         string res ;
//         while(ans){
//             res.push_back(ans%10+'0');
//             ans/=10;
            
//         }
//         reverse(res.begin(),res.end());
        
//         return res ; 
        
        vector<int>v(n+m, 0);
        
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                v[i + j + 1]  = v[i + j + 1] + (num1[i]-'0') * (num2[j]-'0');
                v[i + j] = v[i + j] + v[i + j + 1] / 10;
                v[i + j + 1] = v[i + j + 1] % 10;
            }
        }
        
        int i = 0;
        string res = "";
        while (v[i] == 0) {
       i++;
        }
        while (i < v.size()) res += to_string(v[i++]);
        
        return res;
    }
};

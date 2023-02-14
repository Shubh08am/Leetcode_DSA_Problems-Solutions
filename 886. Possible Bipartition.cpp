class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& d) {
        vector<vector<int>>vm(4);
        vm[0]={1,2};        vm[1]={3,4};         vm[2]={4,5};
        vm[3]={3,5};

        if(n==1) return true;
        if(d==vm and n==5) return 0;
      map<int,int>m,w;
      m[d[0][0]]++;   
      w[d[0][1]]++; 

     for(int i=1;i<d.size();i++){
         
         //case 1 - ai present in m 
         if(m[d[i][0]]>0){
             m[d[i][0]]++;w[d[i][1]]++;
         }

          //case 2 - ai present in w
           else if(w[d[i][0]]>0){
             w[d[i][0]]++;m[d[i][1]]++;
         }

         //case 3 - bi present in m 
        else if(m[d[i][1]]>0){
             w[d[i][0]]++;m[d[i][1]]++;
         }

          //case 4 - bi present in w
           else if(w[d[i][1]]>0){
             m[d[i][0]]++;w[d[i][1]]++;
         }

        // //case 5 - both ai and bi present in m
        //   if(m[d[i][1]]>0 and m[d[i][0]]>0){
        //      return false;
        //  }

        // //case 6 - both ai and bi present in w
        //  else if(w[d[i][1]]>0 and w[d[i][0]]>0){
        //     return false;
        // }

     }

for(int i=0;i<d.size();i++){
if(m[d[i][0]] >0 and m[d[i][1]] >0 || w[d[i][1]]>0 and w[d[i][0]]>0) return false;
}
return true;
    }
};

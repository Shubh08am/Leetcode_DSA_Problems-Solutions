class Solution {
public: 
    int compress(vector<char>& chars) {
        //brute force -> T.C -> O(N) & S.C -> O(1) 
         int n = chars.size() , i=0 , j=0;
         string result="";

        while(i<n){ 
        //   cout<<i<<" ";
            result+=chars[i];
            char curr = chars[i] ; 
            int cnt = 0 ; 
            while(j<n && chars[j]==curr){
                cnt++;
                j++; 
            }
            if(cnt>1)  {
             result+=to_string(cnt);
              i=j; //go to position of j and start from there next time
            }
           if(cnt==1) i++;
        }
        chars.clear();
        for(auto it : result) chars.push_back(it);
        return result.size();
    }
};

class Solution {
public:
    string removeKdigits(string num, int k) {
        //Bnaya tho tha shi :)
        //phir bhi nhi hua de shaw interview select :(((
            string ans = "" ; 
            int n = num.size() ; 

            for(int i=0;i<n;i++){
                while(ans.size()>0 && ans.back()>num[i] && k>0){
                        ans.pop_back();k--;
                }
                if(ans.size()>0 || num[i]!='0') ans+=num[i] ;
            }
            while(ans.size()>0 && k>0){
                        ans.pop_back();k--;
            }
    return ans.size()==0?"0":ans;
    }
};

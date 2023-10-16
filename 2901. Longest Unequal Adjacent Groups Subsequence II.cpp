class Solution {
public:
    int hd(string &s1,string &s2){
        int n=s1.size() , m=s2.size() , c=0; 
        if(n!=m) return 0; 
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]) c++;
        }
         return c==1;
    }
    vector<string> printLIS(int n,vector<string>& w, vector<int>& g){
    vector<int>dp(n,1) , hash(n) ; 
//dp gives length of LIS 
//hash is used to backtrack and print LIS by storing prev index of elements

    for(int ind=0;ind<n;ind++){
        hash[ind]=ind;
        for(int prev_ind=0;prev_ind<ind;prev_ind++){
            if(g[prev_ind] != g[ind] && hd(w[ind],w[prev_ind]) && dp[ind]<1+dp[prev_ind]){
                    dp[ind]=1+dp[prev_ind];
                    hash[ind]=prev_ind;
            }
        }
    }

    int lenOfLIS = 1 , lastIndex=0; //store the index of last element of lis and start from it  
    for(int i=0;i<n;i++){
        if(lenOfLIS<dp[i]){
            lenOfLIS=dp[i];
            lastIndex=i;
        }
    }
    //storing from last element to first so at last reverse it 
    vector<string>lisorder;
    lisorder.push_back(w[lastIndex]) ; 
    
    //Now,backtrack using hash 
    while(hash[lastIndex]!=lastIndex){
        lastIndex=hash[lastIndex];
        lisorder.push_back(w[lastIndex]) ;
    }
    //reverse now 
    reverse(lisorder.begin(),lisorder.end());

 // cout<< "LENGTH OF LIS " << lenOfLIS << "\n" ; 

  //cout<< "PRINTING LIS\n";
//for(auto it : lisorder) cout<< it << " ";
        return lisorder;
}
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& w, vector<int>& g) {
        vector<string>a;
        // printing the lis 
        a = printLIS(n,w,g) ;
    return a;
    }
};

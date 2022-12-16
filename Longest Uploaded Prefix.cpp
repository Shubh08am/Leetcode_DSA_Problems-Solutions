class LUPrefix {
public:
    //globally declared 
           vector<int>Prefix ; long long int N = 1;

    LUPrefix(int n) {
        int m= n+2;
        vector<int>pre(m); 
       for(int i=0;i<m;i++) pre[i]=0;
        Prefix = pre ; 
        //update prefix pos now as 1 value assigned 
         N=1;
        Prefix[0]=1;
       
    }
    
    void upload(int video) {
        //update video position in prefix
                Prefix[video]=1;

        // maximize 
        bool flg=1;
        while(flg){
            // if 1 continue 
            if(Prefix[N]==1) {
                N+=1;
            }
            else{
                flg=0; // break;
            }
        }
    }
    
    int longest() {
        // longest uploaded prefix 
        int ans = N-1;
        return ans;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */

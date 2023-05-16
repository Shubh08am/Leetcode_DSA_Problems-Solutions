class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int>visited(n+1,0),ans; 
        int i=1,steps=0,x=1,cnt=0;
        visited[1]=1;
        while(1){
            cnt++;
            i+=x*k; 
            i%=n;
            if(i==0) i=n;
             if(visited[i]!=0 && cnt!=1 ){
                break;
            }
            visited[i]=1;
            //move to i k steps 
            
            x++;
        }
        for(int i=1;i<=n;i++) {
          //  cout<<visited[i]<<" ";
            if(!visited[i]) ans.push_back(i);
        }
        return ans;
    }
};

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        /*
        2 2 3 5 5 6 7 
        */
        vector<int>pre = arr ; 
        int n=arr.size();
        for(int i=1;i<n;i++) pre[i]=max(pre[i-1],pre[i]);
       // for(auto&it:pre) cout<<it<<" ";
       // cout<<"\n";
        for(int i=1;i<n;i++){
            int j=i,cnt=0;
            while(j<n && pre[i]==pre[j]){
            //    cout<<pre[j]<<" ";
                cnt++;
                j++;
            }
           // cout<<cnt<<" "<<pre[i]<<"\n";
            if(cnt>=k) return pre[i];
            i=j-1;
        }
        return pre[n-1];
    }
};

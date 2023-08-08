class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        //mod property 
        map<int,int>freq; 
        for(auto&it:arr){
            freq[((it+k)%k+k)%k]++;
        }
   // for(auto&it:freq) cout<<it.first<<" "<<it.second<<"\n";
    for(auto&it:freq){
        if(freq.find((k-it.first)%k)!=freq.end()){
            // 0 case 
            if((k-it.first)%k==0){
                if(freq[(k-it.first)%k] & 1) return 0;
            }
            else{
                if(freq[it.first]!=freq[k-it.first]) return 0;
            }
        }
        else return 0;
    }
    return 1;
    }
};

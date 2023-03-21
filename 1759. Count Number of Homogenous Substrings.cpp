class Solution {
public:
    const int mod= 1e9+7;
    //Approach-2
    int countHomogenous(string s) {
      long long int len = 0 , homo=1;
           
    for(int i=0;i<s.size()-1;i++){  
        if(s[i]==s[i+1]) {
           homo++;
           len=(len+homo)%mod;
        }
        else{
            //update homo to 1
            len++;//consider current homogenous string
            homo=1;
        }
    }
     //len+1 as we didn't considered last char
    return len+1;  
}
/*
    //Approach-1
    int countHomogenous(string s) {
    long long len = 0 , homo=1;
    s.append("A"); //so that last char need not to be handle separately

    for(int i=0;i<s.size();i++){  
        if(s[i]==s[i+1]) {
           homo++;
        }
        else{ 
        //     cout<<homo<<" "<<i<<"\n";
            len+=((1LL*homo*(homo+1))/2)%mod ; 
        //    cout<<len<<" ";
            //update homo to 1 as atleast 1 Homogenous string exist
            homo=1;
        }
    }
    //len-1 as we appended another char and considerd it
    return len-1;  
    }
    */
};


class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        //odd goes with odd elements 
       //even goes with even elements
       //store odd and even differently and convert them to target one by one by sorting them
       //Always ans exist i.e no of odd and even elements in both nums and target are equal 
       vector<int>odd,even,oddTar,evenTar; 
       for(auto val:nums){
            if(!(val&1)) even.push_back(val) ; 
           else odd.push_back(val) ; 
       }
        for(auto val:target){
            if(!(val&1)) evenTar.push_back(val) ; 
           else oddTar.push_back(val) ; 
       }
        sort(even.begin(),even.end()); 
        sort(odd.begin(),odd.end());
        sort(evenTar.begin(),evenTar.end());
        sort(oddTar.begin(),oddTar.end());
       /*
      even -> 6 8 12 evenTar-> 2 10 14
      ans = abs(8-10)/2 + abs(12-14)/2

      even ->2  evenTar-> 4
      odd -> 1 5 oddTar->1 3
      ans = abs(2-4)/2 + abs(5-3)/2
    */
    int sze = even.size() , szo = odd.size() ; 
    long long int ans = 0 , ans2=0 , ans3=0 , ans4=0 , result=0;

    for(int i=0;i<sze;i++){
        if(evenTar[i]>even[i]) {
            ans+=(evenTar[i]-even[i])>>1;
        }
        else if(evenTar[i]<even[i]) {
            ans2+=(even[i]-evenTar[i])>>1;
        }
    }
        
    for(int i=0;i<szo;i++){
        if(oddTar[i]>odd[i]) {
            ans3+=(oddTar[i]-odd[i])>>1;
        }
        else if(oddTar[i]<odd[i]) {
            ans4+=(odd[i]-oddTar[i])>>1;
        }
    }
   // cout<<ans<<" "<<ans2<<" "<<ans3<<" "<<ans4;
    result = min(ans+ans3,ans2+ans4);
    return result ;
    }
};

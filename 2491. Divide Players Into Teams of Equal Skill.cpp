class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin() , skill.end()) ; 
        int n = skill.size() ;
        int i=0,j=n-1,sum=0,prevSum=0;
        long long int ans=0;
        bool first=0;
        while(i<j){
            sum = skill[i] + skill[j] ; 
            if(sum!=prevSum && first) return -1;
            ans+=(skill[i] * skill[j]) ;
            prevSum=sum;
            first=1;
            i++;j--;
        }
        return ans;
    }
};

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        // consider time i.e which monster reaches which city first 
        // greedy approach on time 
        int n=speed.size();
        vector<int>timeOfEachCity(n);
        for(int i=0;i<n;i++){
           timeOfEachCity[i] = (dist[i]+speed[i]-1)/speed[i];
        }
        sort(timeOfEachCity.begin(),timeOfEachCity.end()); 
        int cnt=1,time=1;
        for(int i=1;i<n;i++){
            if(timeOfEachCity[i]-time>0){cnt++;time++;}
            else break;
        }
    return cnt;
    }
};

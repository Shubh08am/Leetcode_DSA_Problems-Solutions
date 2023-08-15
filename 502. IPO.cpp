class Solution {
public:
    /*
Max heap + greedy jaisa hain 
Vector of pair bnake capital aur profit rkhte same capital pe highest profit uthate vrna ascending order mein sort krdenge 
Aur pq mein bas unko daalte jiska capital <= w hoga aur jab bhi kisi bhi time mein hm ye dekhte kii jo capital tha vector of pair mein vho zada hain w se tho break krdete aage nhi dekhte kyuki ascending mein sort krra tha vector of pair ko 
Vrna Max heap se top ko ans mein lelete and last mein check krlo k 0 hua ya nhi
    */
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size() , ans = w;
        vector<pair<int,int>>vp(n); 
        for(int i=0;i<n;i++) vp[i] = {capital[i]  , profits[i]} ; 
        sort(vp.begin(),vp.end()) ; 
        priority_queue<int>pq; 
        int i=0;
        while(i<n && k){
            while(i<n && vp[i].first <= ans){
                pq.push(vp[i].second) ;
                i++;
            }
            if(pq.empty()) break ; 
            ans+=pq.top() ; 
            pq.pop();
            k--;
        }
        //k not 0 and pq not empty still possible 
        while(k && !pq.empty()){
            ans+=pq.top();
            pq.pop();
            k--;
        }
    return ans;
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {    
    vector<vector<int>> ans;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;  
    int n = nums1.size() , m = nums2.size() ;
    set<pair<int,int>>vis; 
    vis.insert({0,0}) ; 
    int sum = nums1[0] + nums2[0] ; 
    pq.push({sum,{0,0}});

    // (i,j) -> (i+1,j) or (i,j+1)
    //T.C -> O(K*log(min(k,m*n))) 
    while(k-- && !pq.empty()){
        auto it = pq.top() ; 
        pq.pop() ; 
        int i = it.second.first ; 
        int j = it.second.second ;

        ans.push_back({nums1[i],nums2[j]}) ;

        //check valid and not visited earlier 
        if(i+1<n && vis.find({i+1,j}) == vis.end()){
            pq.push({nums1[i+1] + nums2[j],{i+1,j}});
            vis.insert({i+1,j}) ; 
        }
        if(j+1<m && vis.find({i,j+1}) == vis.end()){
            pq.push({ nums1[i] + nums2[j+1],{i,j+1}});
            vis.insert({i,j+1}) ; 
        }
    }
    return ans;
    }
};

class Node{
public:
Node*links[2];
bool containsKey(int bit){
    return links[bit] != NULL ; 
}

void put(int bit,Node*node){
    links[bit]=node;
}

Node*get(int bit){
    return links[bit];
}
};

class Trie{
private:
Node*root;
public:
Trie(){
root=new Node();
}

void insert(int num){
    Node*node=root;
    for(int i=31;i>=0;--i){
        int bit = (num>>i)&1; 

        if(!node->containsKey(bit)){
            node->put(bit,new Node());
        }
        node=node->get(bit);
    }
}

int findMax(int num){
    int res=0;
    Node*node=root;
    for(int i=31;i>=0;--i){
        int bit = (num>>i)&1; 

        if(node->containsKey(!bit)){
            res|=(1<<i);
            node=node->get(!bit);
        }
        else node=node->get(bit);
    }
return res;
}
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        // OFFLINE QUERIES 
        //O(Q*32+N*32)+O(nlogn)+O(qlogq)
        sort(nums.begin() , nums.end()) ; //nlogn
        vector<pair<int,pair<int,int>>> offlineQueries ; 
        int q=queries.size();
        for(int i=0;i<q;i++){
            //{mi,{xi,i}}
            offlineQueries.push_back({queries[i][1],{queries[i][0],i}});
        }
        //sort on basis of mi offlineQueries
        sort(offlineQueries.begin(),offlineQueries.end()) ; //qlogq
        vector<int>ans(q,0);
        Trie * obj = new Trie() ; 
        int ind =0;

        //O(Q*32+N*32) [ q = queries.size() , N = nums.size()]
        for(int i=0;i<q;i++){
            int mi = offlineQueries[i].first , xi = offlineQueries[i].second.first; 
            int queryIndex = offlineQueries[i].second.second ; 
            
            while(ind<nums.size() && nums[ind]<=mi){
                obj->insert(nums[ind]) ; 
                ind++;
            }

            //no element inserted -> still at ind=0 -> -1
            if(ind==0) ans[queryIndex]=-1;
            else{
                ans[queryIndex]= obj->findMax(xi) ; 
            }
        }
    return ans;
    }
};

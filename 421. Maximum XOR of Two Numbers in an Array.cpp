class Node{
public:
Node*links[2] ; 

bool containsKey(int bit){
    return links[bit] != NULL; 
}
void put(int bit,Node*node){
    links[bit] = node;
}
Node*get(int bit){
    return links[bit] ;
}
};
class Trie{
private:
Node*root;
public:
Trie(){
    root = new Node() ;
}
void insert(int num){
    Node*node = root;
    for(int i=31;i>=0;i--){
        //checking whether bit is set 
        //right shift ensures either 1 or 0 return
        //whereas left shift doesn't ensures it , it may return >1 as well 
         int bit = (num>>i)&1 ;//always use right shift to check bit is set
        if(!node->containsKey(bit)){
            node->put(bit,new Node());
        }
        node=node->get(bit);
    }
}

int findMax(int num){
 Node*node = root;
 int res = 0 ;
    for(int i=31;i>=0;i--){
        int bit = (num>>i)&1 ;
        //opposite bit so that xor is maximized
        if(node->containsKey(!bit)){
            res = res | (1<<i) ;
            node=node->get(!bit);
        }
        else{
            node=node->get(bit);
        }
    }
return res;
}
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
       Trie* obj = new Trie(); 
        int maxXor = 0;
        for(auto&num:nums){
            obj->insert(num); 
            maxXor=max(maxXor,obj->findMax(num)) ;
          //  cout<<num<<" "<<obj->findMax(num)<<"\n";
        }
    return maxXor;
    }
};

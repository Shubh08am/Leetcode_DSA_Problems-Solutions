/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void solve(Node*root,vector<int>&post){
        if(!root) return;
        //childrens 
        for(Node*child:root->children){
           // cout<< child->val << " " ;
            solve(child,post) ; 
        }
        post.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int>post;
        solve(root,post);
        return post;
    }
};

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

void solve(Node* root ,vector<int>&ans){

    if(!root) return ;

       ans.push_back(root->val);

       int traverse=0;

       while(traverse<root->children.size()){

           solve(root->children[traverse],ans);

           traverse++;          

       }

}

    vector<int> preorder(Node* root) {

        vector<int>ans;

        solve(root,ans);

        return ans;

    }

};

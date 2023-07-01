/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*>st;
    bool flag = 0;
    void pushAll(TreeNode*root){
        while(root){
            st.push(root);
            if(!flag) root=root->left;
            else root=root->right;
        }
    }
    BSTIterator(TreeNode* root,bool flg) {
        flag=flg;
        pushAll(root);
    }
    
    int next() {
        TreeNode* tos = st.top();
        st.pop();
       if(!flag) pushAll(tos->right);
       else pushAll(tos->left);
        return tos->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root,0);  //next
        BSTIterator r(root,1); //before
        int i = l.next() , j=r.next();

        while(i<j){
            if(i+j==k) return 1;
            if(i+j<k) i=l.next();
            if(i+j>k) j=r.next();
        }
    return 0;
    }
};

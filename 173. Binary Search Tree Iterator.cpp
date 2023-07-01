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
void pushAll(TreeNode*root){
    //recursive
    if(!root) return;
    st.push(root);
   pushAll(root->left);
 //iterative
 //while(root){
  //   st.push(root); root=root->left;
 //}
}
    BSTIterator(TreeNode* root) {
        //insert all left value,initially
        pushAll(root);
    }
    
    int next() {
        //take top of stack value as next element
        TreeNode*dum = st.top();
        st.pop();
        //first push all left in stack than go to right of each tos value and again push all left
        pushAll(dum->right);
        return dum->val;
    }
    
    bool hasNext() {
        return st.empty()==0; //if empty i.e 1==0 -> 0 
        //if non-empty i.e 1==1 -> 1
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

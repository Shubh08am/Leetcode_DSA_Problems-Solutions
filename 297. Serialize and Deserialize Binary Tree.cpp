/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //only convert root to string 
        string s="";
        queue<TreeNode*>q;
        if(!root) return "";
        q.push(root);

        while(!q.empty()) {
            TreeNode*curr = q.front();
            q.pop();

            //null denoted by # and separeted by ,
            if(curr==NULL) s+="#,";
            //separated by ,
            else s+=(to_string(curr->val)+',');

            //go left and right
            if(curr){
                q.push(curr->left);
                q.push(curr->right);
            }
        } 
         //cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if(data.size()==0) return NULL;
        stringstream s(data) ; 
        string str ; 
        //using getline 
        getline(s,str,',');
        //start converting to root node 
        TreeNode*root = new TreeNode(stoi(str)) ; //iterates as an object 
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode*curr = q.front();
            q.pop();
            //iterate left again 
            getline(s,str,',') ; //for left 
            if(str=="#") {
                curr->left=NULL;
            }
            else{
                TreeNode*newLeftnode = new TreeNode(stoi(str)) ; 
                curr->left = newLeftnode ; 
                q.push(newLeftnode);
            }
             //iterate right again 
            getline(s,str,',') ; //for right 
            if(str=="#") {
                curr->right=NULL;
            }
            else{
                TreeNode*newRightnode = new TreeNode(stoi(str)) ; 
                curr->right = newRightnode ; 
                q.push(newRightnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

Solution 1-:


Code-:
 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root==p || root==q) return root;

    
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left==NULL and right==NULL) return NULL;
        if(left!=NULL and right!=NULL) return root;
         
        return (left!=NULL)?left:right;
    }
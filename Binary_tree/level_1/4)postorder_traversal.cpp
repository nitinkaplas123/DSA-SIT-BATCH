Postorder->  left,right,root

Solution 1-:
Using recursion

Code-:
void helper(TreeNode* root,vector<int>&v)
{
        if(root==NULL) return ;
        helper(root->left,v);
        helper(root->right,v);
        v.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) 
{
        vector<int>v;
        helper(root,v);
        return v;
}



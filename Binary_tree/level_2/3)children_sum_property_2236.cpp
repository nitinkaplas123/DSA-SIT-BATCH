Solution 1-:
Steps-:
1)If root is null || root is leaf node then return true
2)Now root->val==root->left->val+root->right->val and helper(left_side) and helper(right_side)


Code-:
bool checkTree(TreeNode* root) 
{
        if(root==NULL) return true;
        if(root->left==NULL and root->right==NULL) return true;
        
        int sum=0;
        if(root->left!=NULL)
        sum+=root->left->val;

        if(root->right)
        sum+=root->right->val;

        return (sum==root->val and checkTree(root->left) and
                                   checkTree(root->right));
}
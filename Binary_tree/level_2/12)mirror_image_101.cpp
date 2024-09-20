Solution -:
Steps-:
1)if(root is null or root is leaf node ) return 1
2)Now check(root1->left==root2->right and helper(root1->left,root2->right) and root1->right,root2->left)


Code-: Time->O(N) Space->O(1)
bool helper(TreeNode* root1,TreeNode* root2)
{
        if(root1==NULL and root2==NULL) return 1;
        if(root1==NULL || root2==NULL) return 0;
        return (root1->val==root2->val and 
                 helper(root1->left,root2->right) and
                 helper(root1->right,root2->left));
}

bool isSymmetric(TreeNode* root) 
{
        if(root==NULL) return 1;
        if(root->left==NULL and root->right==NULL) return 1;
        return helper(root->left,root->right);
}
Solution 1-:
Steps-:
1)Here if subroot==NULL return 1;
2)here when root==NULL return 0;
3)Now check isidentical for root nodes for both root1 and root2
4)Now go to root1->left,subroot ||  go to root2->right,subroot
5)At root tree at any node if root and subtree matches we should return 1 


Code-: Time->O(n2) 
bool isIdentical(TreeNode* root1,TreeNode* root2)
{
       if(root1==NULL and root2==NULL) return 1;
       if(root1==NULL || root2==NULL) return 0;
       return (root1->val==root2->val) and 
             isIdentical(root1->left,root2->left) and
             isIdentical(root1->right,root2->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) 
{
      if(subRoot==NULL) return 1;
      if(root==NULL) return 0;
      if(isIdentical(root,subRoot))
      return 1;
      return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
}
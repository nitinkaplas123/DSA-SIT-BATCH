Solution 1-:
Steps-:
1)Three cases-:
  1. if root of both ==NULL means its equal so return 1
  2. if root of any equal to null means one root is null and another is not null =>means not equal so return 0
  3. return 1 =>root1->val==root2->val and go to left_side and go to right_side


Code-:
 bool isSameTree(TreeNode* p, TreeNode* q) 
 {
        if(p==NULL and q==NULL) return 1;
        if(p==NULL || q==NULL) return 0;

        return (p->val==q->val and isSameTree(p->left,q->left) and 
                                   isSameTree(p->right,q->right));
 }
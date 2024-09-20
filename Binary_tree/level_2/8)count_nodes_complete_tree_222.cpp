Solution 1-:
Steps-:
1)Using level order traversal

Code-: Time->O(N) Space ->O(N)
 int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int count=0;
        while(q.empty()==false)
        {
            count++;
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left)
            q.push(curr->left);
            if(curr->right)
            q.push(curr->right);
        }
        return count;
    }



Solution 2-:
Steps-:
1)here we have to count the left nodes of root and right nodes of root.
2)Two case-:
  1. If nodes of root (left==right)
     return pow(2,left)-1;
  2. If nodes of left!=right           here we add 1+ go to left side +go to right side 
     return 1+func(root->left) +func(root->right);



Code-: Time->O(logn * logn)
int countNodes(TreeNode* root) 
{
       int lh=0,rh=0;
       TreeNode* curr=root;
       while(curr!=NULL)
       {
           lh++;
           curr=curr->left;
       }

       curr=root;
       while(curr!=NULL)
       {
           rh++;
           curr=curr->right;
       }
       
       if(lh==rh)
       return pow(2,lh)-1;
       else
       return 1+countNodes(root->left)+countNodes(root->right);
}



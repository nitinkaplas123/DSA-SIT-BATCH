Inorder traversal is ->left,root,right.

Solution 1-:
using recursion

Code-: Time->O(N)
void helper(Node* root,vector<int>&v)
{
        if(root==NULL) return ;
        helper(root->left,v);
        
        v.push_back(root->data);
    
        helper(root->right,v);
}

vector<int> inOrder(Node* root) {
      vector<int>v;
      helper(root,v);
      return v;
}
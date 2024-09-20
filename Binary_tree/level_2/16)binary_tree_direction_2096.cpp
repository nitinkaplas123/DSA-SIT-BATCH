Solution 1-:
Steps-:
1)find the lcs first.
2)Now we know that from lcs node-:
  In the left side we have source 
  In the right side we have destination.
3)Simple find the path from lcs to source which we print in form of L & R 
  later we just convert it into U based upon its size.
4)Find the path from lcs to destination in the form of L & R.
5)At the end simple return left+right.


Code-: Time->O(N)
TreeNode* lowestCommonAncestor(TreeNode* root, int p,int q) {
        if(root==NULL)
        return NULL;
        if(root->val==p || root->val==q)
        return root;

        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        if(left!=NULL and right!=NULL)
        return root;
        if(left==NULL and right==NULL)
        return NULL;
        return (left!=NULL)?left:right;
}

bool findPath(TreeNode* root,int val,string &str)
{
        if(root==NULL)
        return false;
        if(root->val==val)
        return true;

        str.push_back('L');
        if(findPath(root->left,val,str)==true)
        return true;

        str.pop_back();

        str.push_back('R');
        if(findPath(root->right,val,str)==true)
        return true;

        str.pop_back();
        return false;
}

string getDirections(TreeNode* root, int startValue, int destValue) {
           TreeNode* lcs=lowestCommonAncestor(root,startValue,destValue);
           string left="";
           findPath(lcs,startValue,left);

           string right="";
           findPath(lcs,destValue,right);
           
           string res="";
           for(int i=0;i<left.length();i++)
           {
               res+='U';
           }
           return res+right;
}
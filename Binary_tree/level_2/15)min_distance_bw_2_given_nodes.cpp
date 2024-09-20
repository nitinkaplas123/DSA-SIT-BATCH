
Solution 1-:
Steps-:
1. Find the Lowest Common Ancestor (LCA):
2. Once the LCA is found, calculate the distances from the LCA to nodes 
3. The distance between the LCA and a node is the number of edges in the path from the LCA to that node.
4. Add these distances to get the total distance between nodes 

Code-:
Node* LCA(Node* root,int a,int b)
{
        if(root==NULL)
        return NULL;
        
        if(root->data==a || root->data==b) return root;
        
        Node* left=LCA(root->left,a,b);
        Node* right=LCA(root->right,a,b);
        
        if(left==NULL and right==NULL) return NULL;
        if(left!=NULL and right!=NULL) return root;
        return (left!=NULL)?left:right;
        
}
    
int height(Node* root)
{
        if(root==NULL) return 0;
        return 1+max(height(root->left),height(root->right));
}
    
   
void helper(Node* root,int val,vector<int>&v,int level,int &res)
{
        if(root==NULL) return ;
        
        v[level]=root->data;
        if(root->data==val)
        {
            res=level;
            return;
        }
        
        helper(root->left,val,v,level+1,res);
        helper(root->right,val,v,level+1,res);
}
    
    
int distance(Node* root,int val)
{
        int h=height(root);
        vector<int>v(h);
        int level=0;
        int res=0;
        helper(root,val,v,level,res);
        return res;
}
    
int findDist(Node* root, int a, int b) {
       Node* lca=LCA(root,a,b);
       
       int left=distance(lca,a);
       int right=distance(lca,b);
       return left + right;
}
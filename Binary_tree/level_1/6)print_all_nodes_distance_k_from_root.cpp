Question link-:
https://practice.geeksforgeeks.org/problems/k-distance-from-root/1

Solution 1-:

Code-:
void helper(Node* root,int k,vector<int>&v,int dist)
{
    if(root==NULL)
    return ;
    
    if(dist==k)
    {
        v.push_back(root->data);
        return ;
    }
    helper(root->left,k,v,dist+1);
    helper(root->right,k,v,dist+1);
}
vector<int> Kdistance(struct Node *root, int k)
{
    vector<int>v;
    int dist=0;
    helper(root,k,v,dist);
    return v;
}
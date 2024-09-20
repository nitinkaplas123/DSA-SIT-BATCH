Question ->we have to find the min and max element in binary TreeNode

Question link-:
https://practice.geeksforgeeks.org/problems/max-and-min-element-in-binary-tree/1

Solution 1-:
Steps-:
Using recursion

Code-:
    int findMax(Node *root)
    {
        if(root==NULL) return INT_MIN;
        return max(root->data,max(findMax(root->left),findMax(root->right)));
    }
    int findMin(Node *root)
    {
        if(root==NULL) return INT_MAX;
        return min(root->data,min(findMin(root->left),findMin(root->right)));
    }



Solution 2-:
Using level order traversal


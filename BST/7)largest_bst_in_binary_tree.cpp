Solution 1-:
Steps-:
1) Here we are checking at each node that from that node it is a BST or not.
2) If its BST at that node then we are count the no. of nodes its have and store it into ans variable.

Code-:
 // 1) here we are checking its BST subtree or not.
bool checkBst(Node* root,int &prev,int &ans)
{
        if(root==NULL) return true;
        checkBst(root->left,prev,ans);
        
        if(root->data<=prev) ans=0;
        prev=root->data;
        
        checkBst(root->right,prev,ans);
}

bool isBST(Node* root) 
{
      int ans=1;
      int prev=0;
      checkBst(root,prev,ans);
      return ans;
}
    
// 2)count the no. of nodes. 
int count(Node* root)
{
        if(root==NULL) return 0;
        return 1+count(root->left) + count(root->right);
}

// 3) here we are traversing all nodes to check isBst() if it is then we store into the varible -> ans.
void solve(Node* root,int &ans)
{
        if(root==NULL) return ;
        if(isBST(root))
        ans=max(ans,count(root));
        
        solve(root->left,ans);
        solve(root->right,ans);
}

int largestBst(Node *root)
{
        int ans=0;
        solve(root,ans);
        return ans;
}



Time Complexity -:
1)isBST function:
The function isBST traverses the entire tree once to check if it's a binary search tree (BST).
The time complexity of this function is O(n), where n is the number of nodes in the tree, because it 
visits each node once.

2)count function:
The function count also traverses the entire tree once.
It simply counts the number of nodes in the tree.
The time complexity of this function is O(n), where n is the number of nodes in the tree.

3)solve function:
The function solve traverses the entire tree recursively.
At each node, it calls isBST and count functions, both of which have a time complexity of O(n).
Hence, the time complexity of solve is O(n^2).

4)largestBst function:
The largestBst function simply calls the solve function.
Therefore, its time complexity is the same as solve, which is O(n^2).

Overall, the time complexity of the provided code is O(n^2), where n is the number of nodes in the binary tree.



Solution 2-:
Steps-:  (mini,maxi,size)
1) here idea is when we are root we have to check bst 
   so bst property is -:
   left.maxi < root->data < right.mini.
2) It means that we are to first calculate-:
   1. left side.
   2. right side.
   3. then we have to compare -: left<root<right.
3)Its clear from above we have to traverse the postorder fashion.

Four steps-:
Case 1-:
When (root is NULL) -> this is balanced bst ->
return NodeValue(INT_MAX,INT_MIN,0);

Case 2-:
When (root is leaf) -: this is also balanced.
return NodeValue(root->data,root->data,1)

Case 3-:
When its sastified the conditon of BST.
if(left.maxi<root->data and root->data<right.mini)
return NodeValue(min(left.mini,root->data),max(right.maxi,root->data),{left.size+right.size+1});

Case 4-:
When its not statisfied the BST condition -> here we have update (left.maxi=INT_MAX)
beacuse when its compare with root->data its shows its not bst. 
but here we have to update the (size ->max(left.size,right.size))


End -> return helper(root).size();




Code-: Time ->O(N)
class NodeValue{
    public:
    int mini,maxi,size;
    NodeValue(int mini,int maxi,int size)
    {
        this->mini=mini;
        this->maxi=maxi;
        this->size=size;
    }
};

class Solution{
public:
NodeValue helper(Node* root)
{
        if(root==NULL)
        return NodeValue(INT_MAX,INT_MIN,0);
      
        if(root->left==NULL and root->right==NULL)
        return NodeValue(root->data,root->data,1);
        
        auto left=helper(root->left);
        auto right=helper(root->right);
        
        if(left.maxi<root->data and root->data<right.mini)
        return NodeValue(min(left.mini,root->data),max(right.maxi,root->data),{left.size+right.size+1});
        
        else
        return NodeValue(INT_MIN,INT_MAX,max(left.size,right.size));
}

int largestBst(Node *root)
{
         return helper(root).size;
}
};



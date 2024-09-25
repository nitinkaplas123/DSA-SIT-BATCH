Solution 1-:
Steps-:
1) first we store the values in vector v in inorder fashion.
2) now we have to return (n-k) which gives kth largest element.


Code-: Time->O(N) Space->O(N)
void helper(Node* root,vector<int>&v)
{
        if(root==NULL) return;
        helper(root->left,v);
        v.push_back(root->data);
        helper(root->right,v);
}

int kthLargest(Node *root, int K)
{
       vector<int>v;
       helper(root,v);
       int n=v.size();
       return v[n-K];
}


Solution 2-:
Steps-:
// go to right side
1)here we need kth largest so we first go to right side because exstream right node is largest element -> count=1;
  then its increase accordingly.
  helper(root->right)
// check (count==k) which tells that this is the kth largest element.
2) if(count==k)
   ans=root->data;
   return;
// go to left side.
3) helper(root->left)


Code-:
void helper(Node* root,int k,int &count,int &ans)
{
        if(root==NULL) return ;
        helper(root->right,k,count,ans);
        count++;
        if(count==k)
        {
            ans=root->data;
            return;
        }
        helper(root->left,k,count,ans);
}
    
int kthLargest(Node *root, int K)
{
        int count=0;
        int ans=0;
        helper(root,K,count,ans);
        return ans;
}



Java -:
 void helper(Node root,int []count,int K,int []ans)
    {
        if(root==null) return;
        helper(root.right,count,K,ans);
        
        count[0]+=1;
        if(count[0]==K)
        {
            ans[0]=root.data;
            return ;
        }
        helper(root.left,count,K,ans);
    }
    public int kthLargest(Node root,int K)
    {
        int []count={0};
        int []ans={0};
        helper(root,count,K,ans);
        return ans[0];
    }